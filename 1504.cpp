#include <iostream>
#include <queue>
#define INF 0x7fffffff
using namespace std;

struct info{
    int vertex;
    int cost;

    info(int vertex, int cost): vertex(vertex), cost(cost) {}
    bool operator<(const info& other) const{
        return this->cost > other.cost;
    }
};

int N,E;
int adj[801][801];

int dijkstra(int s, int e) {
    priority_queue<info> pq;
    int dist[801];
    fill_n(dist, 801, INF);
    dist[s] = 0;
    pq.push(info(s, 0));
    while(!pq.empty()) {
        info cur = pq.top(); pq.pop();
        if(cur.cost > dist[cur.vertex])
            continue;
        for(int i=1; i<=N; i++) {
            if(adj[cur.vertex][i] != 0) {
                if(dist[i] > dist[cur.vertex] + adj[cur.vertex][i]) {
                    dist[i] = dist[cur.vertex] + adj[cur.vertex][i];
                    pq.push(info(i, dist[cur.vertex] + adj[cur.vertex][i]));
                }
            }
        }
    }
    return dist[e];
}

int main() {
    cin >> N >> E;
    for(int i=0; i<E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
        adj[b][a] = c;
    }
    int v1, v2;
    cin >> v1 >> v2;
    int d0 = dijkstra(1, v1);
    int d1 = dijkstra(v1, v2);
    int d2 = dijkstra(v2, N);
    int r1;
    int d3 = dijkstra(1, v2);
    int d4 = dijkstra(v2, v1);
    int d5 = dijkstra(v1, N);
    int r2;
    if(d0 == INF || d1 == INF || d2 == INF) {
        r1 = INF;
    }
    else {
        r1 = d0+d1+d2;
    }
    if(d3 == INF || d4 == INF || d5 == INF) {
        r2 = INF;
    }
    else {
        r2 = d3+d4+d5;
    }
    if(r1 == INF && r2 == INF)
        cout << -1;
    else
        cout << ((r1<r2) ? r1 : r2);
    return 0;
}