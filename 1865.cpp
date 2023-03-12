#include <iostream>
#include <vector>
#define MAX_VERTEX 501
#define INF 0x7fffffff
using namespace std;

struct Edge {
    int from;
    int to;
    int cost;

    Edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
};

bool bellman_ford(int n, vector<Edge>& edges) {
    int dist[MAX_VERTEX];
    fill_n(dist, MAX_VERTEX, 0);
    dist[1] = 0;
    for(int i=0; i<n; i++) {
        for(Edge edge : edges) {
            if(dist[edge.from] + edge.cost < dist[edge.to]) {
                if(i == n-1)
                    return false;
                dist[edge.to] = dist[edge.from] + edge.cost;
            }
        }
    }
    return true;
}

void solve() {
    int n, m, w;
    vector<Edge> edges;
    cin >> n >> m >> w;
    for(int i=0; i<m; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        edges.emplace_back(s, e, t);
        edges.emplace_back(e, s, t);
    }
    for(int i=0; i<w; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        edges.emplace_back(s, e, -t);
    }
    if(bellman_ford(n, edges)) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    for(int i=0; i<tc; i++) {
        solve();
    }
    return 0;
}