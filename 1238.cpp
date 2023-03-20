#include <iostream>
#include <queue>
#define INF 0x7fffffff
using namespace std;

struct element {
    int vertex;
    int dist;
    element(int vertex, int dist) : vertex(vertex), dist(dist) {}

    bool operator<(const element& other) const {
        return this->dist > other.dist;
    }
};

int n,m,x;

int adj[1001][1001];

int dist_come[1001];
int dist_go[1001];

void dijkstra_go() {
    fill_n(dist_go, 1001, INF);
    priority_queue<element> pq;
    dist_go[x] = 0;
    pq.push(element(x, 0));
    while(!pq.empty()) {
        element cur = pq.top();
        pq.pop();
        if(cur.dist > dist_go[cur.vertex])
            continue;
        for(int i=1; i<=n; i++) {
            if(adj[cur.vertex][i] != 0) {
                if(cur.dist + adj[cur.vertex][i] < dist_go[i]) {
                    pq.push(element(i, cur.dist + adj[cur.vertex][i]));
                    dist_go[i] = cur.dist + adj[cur.vertex][i];
                }
            }
        }
    }
}

void dijkstra_come() {
    fill_n(dist_come, 1001, INF);
    priority_queue<element> pq;
    dist_come[x] = 0;
    pq.push(element(x, 0));
    while(!pq.empty()) {
        element cur = pq.top();
        pq.pop();
        if(cur.dist > dist_come[cur.vertex])
            continue;
        for(int i=1; i<=n; i++) {
            if(adj[i][cur.vertex] != 0) {
                if(cur.dist + adj[i][cur.vertex] < dist_come[i]) {
                    pq.push(element(i, cur.dist + adj[i][cur.vertex]));
                    dist_come[i] = cur.dist + adj[i][cur.vertex];
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> x;
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
    }
    dijkstra_come();
    dijkstra_go();
    int res = 0;
    for(int i=1; i<=n; i++) {
        if(dist_come[i] + dist_go[i] > res)
            res = dist_come[i] + dist_go[i];
    }
    cout << res;

    return 0;
}