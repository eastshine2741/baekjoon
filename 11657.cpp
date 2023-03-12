#include <iostream>
#include <vector>
#define INF 0x7fffffff
using namespace std;

struct Edge {
    int from;
    int to;
    int cost;

    Edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
};

int n,m;
vector<Edge> edges;

void bellman_ford() {
    long long dist[501];
    fill_n(dist, 501, INF);
    dist[1] = 0;
    for(int i=0; i<n; i++) {
        for(Edge edge : edges) {
            if(dist[edge.from] != INF && dist[edge.from] + edge.cost < dist[edge.to]) {
                if(i == n-1){
                    cout << -1 << "\n";
                    return;
                }
                dist[edge.to] = dist[edge.from] + edge.cost;
            }
        }
    }
    for(int i=2; i<=n; i++) {
        if(dist[i] == INF)
            cout << -1 << "\n";
        else
            cout << dist[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<m; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        edges.emplace_back(s, e, t);
    }
    bellman_ford();
    return 0;
}