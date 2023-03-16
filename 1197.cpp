#include <iostream>
#include <vector>
#include <queue>
#define MAX_VERTEX 10001
using namespace std;

struct edge {
    int src;
    int dest;
    int cost;

    edge(int src, int dest, int cost): src(src), dest(dest), cost(cost) {}

    bool operator<(const edge& other) const {
        return this->cost > other.cost;
    }
};

int n,m;
int root[MAX_VERTEX];
int rank_[MAX_VERTEX];
priority_queue<edge> pq;
int sum;

int find(int x) {
    if(root[x] == x) {
        return x;
    }
    else {
        return root[x] = find(root[x]);
//        return root[x];
    }
}

void union_(int x, int y) {
    x = find(x);
    y = find(y);
    if(x==y)
        return;
    if(rank_[x] < rank_[y]) {
        root[x] = y;
    }
    else if(rank_[x] > rank_[y]) {
        root[y] = x;
    }
    else {
        root[x] = y;
        rank_[y]++;
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<=n; i++) {
        root[i] = i;
    }
    fill_n(rank_, n+1, 1);
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push(edge(a, b, c));
    }
    while(!pq.empty()) {
        edge edge = pq.top();
        pq.pop();

        if(find(edge.src) != find(edge.dest)) {
            sum += edge.cost;
            union_(edge.src, edge.dest);
        }
    }
    cout << sum;
    return 0;
}