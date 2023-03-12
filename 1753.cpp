#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX_VERTEX 20001

int v,e;
int k;
vector<pair<int, int>> adj[MAX_VERTEX];
int dist[MAX_VERTEX];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill_n(dist, MAX_VERTEX, 0x7fffffff);
    cin >> v >> e;
    cin >> k;
    for(int i=0; i<e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(c, b);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push(make_pair(0, k));
    dist[k] = 0;
    while(!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();

        for(pair<int,int> next : adj[cur.second]) {
            if(cur.first + next.first < dist[next.second]) {
                pq.push(make_pair(cur.first + next.first, next.second));
                dist[next.second] = cur.first + next.first;
            }
        }
    }
    for(int i=1; i<=v; i++) {
        if(dist[i] == 0x7fffffff)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }

    return 0;
}