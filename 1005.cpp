#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solve() {
    int n, k, w;
    int dp[1001];
    int in_links_num[1001];
    vector<int> in_links[1001];
    vector<int> out_links[1001];
    vector<int> order;
    queue<int> q;
    bool visited[1001];
    int root;
    fill_n(visited, 1001, false);
    fill_n(in_links_num, 1001, 0);

    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        cin >> dp[i];
    }
    for(int i=0; i<k; i++) {
        int a,b;
        cin >> a >> b;
        out_links[a].push_back(b);
        in_links[b].push_back(a);
        in_links_num[b]++;
    }
    cin >> w;

    for(root=1; root<=n; root++) {
        if(in_links_num[root] == 0) {
            q.push(root);
        }
    }
    while(!q.empty()) {
        int cur = q.front(); q.pop();

        order.push_back(cur);
        for(int next : out_links[cur]) {
            in_links_num[next]--;
            if(in_links_num[next] == 0) {
                q.push(next);
            }
        }
    }

    for(int cur: order) {
        int max = 0;
        for(int from: in_links[cur]) {
            if(max < dp[from])
                max = dp[from];
        }
        dp[cur] += max;
    }
    return dp[w];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    vector<int> ans;
    cin >> t;
    for(int i=0; i<t; i++) {
        ans.push_back(solve());
    }
    for(int a: ans) {
        cout << a << "\n";
    }

    return 0;
}