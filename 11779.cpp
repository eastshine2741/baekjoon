#include <iostream>
#include <queue>
#include <climits>
#define INF LONG_LONG_MAX
using namespace std;
typedef long long LONG;

struct state{
    int node;
    LONG dist;

    state(int node, LONG dist): node(node), dist(dist) {}
    bool operator<(const state& other) const {
        return this->dist > other.dist;
    }
};

int n,m;
LONG adj[1001][1001];
int s,e;
LONG dist[1001];
int route[1001];

void dijkstra() {
    fill_n(dist, 1001, INF);
    dist[s] = 0;
    priority_queue<state> pq;
    pq.push(state(s, 0));
    while(!pq.empty()) {
        state cur = pq.top(); pq.pop();
        if(cur.dist > dist[cur.node])
            continue;
        for(int i=1; i<=n; i++) {
            if(adj[cur.node][i] != INF) {
                if(cur.dist + adj[cur.node][i] < dist[i]) {
                    dist[i] = cur.dist + adj[cur.node][i];
                    route[i] = cur.node;
                    pq.push(state(i, cur.dist + adj[cur.node][i]));
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&adj[0][0], &adj[1000][1001], INF);

    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        if(adj[a][b] > c)
            adj[a][b] = c;
    }
    cin >> s >> e;
    dijkstra();
    cout << dist[e] << "\n";
    int c = e;
    vector<int> res;
    res.push_back(e);
    while(c != s) {
        res.push_back(route[c]);
        c = route[c];
    }
    cout << res.size() << "\n";
    while(!res.empty()) {
        cout << res.back() << " ";
        res.pop_back();
    }
    return 0;
}