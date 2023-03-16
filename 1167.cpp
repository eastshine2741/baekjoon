#include <iostream>
#include <vector>
using namespace std;

struct edge {
    int dest;
    int cost;
};

int n;
vector<edge> tree[100001];

void dfs(int node, int cost, int from, edge* res) {
    if(tree[node].size() == 1 && tree[node].back().dest == from) {
        if(res->cost < cost) {
            res->cost = cost;
            res->dest = node;
        }
    }
    for(edge e: tree[node]) {
        if(e.dest == from) {
            continue;
        }
        dfs(e.dest, cost + e.cost, node, res);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++) {
        int v;
        cin >> v;
        for(int j=0; ; j++) {
            int a, b;
            cin >> a;
            if(a == -1)
                break;
            cin >> b;
            tree[v].push_back({a, b});
        }
    }
    edge m = {0, 0};
    dfs(1, 0, 0, &m);

    edge r = {0, 0};
    dfs(m.dest, 0, 0, &r);
    cout << r.cost << "\n";

    return 0;
}