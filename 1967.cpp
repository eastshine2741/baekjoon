#include <iostream>
#include <vector>
using namespace std;

struct edge {
    int dest;
    int cost;
};

int n;
vector<edge> tree[10001];
int m1, m2;

int max_leaf;
int max_leaf_value;

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
    for(int i=0; i<n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }
    edge m = {0, 0};
    dfs(1, 0, 0, &m);

    edge r = {0, 0};
    dfs(m.dest, 0, 0, &r);
    cout << r.cost << "\n";

    return 0;
}