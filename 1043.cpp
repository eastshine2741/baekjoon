#include <iostream>
#include <queue>
using namespace std;

int n,m;
queue<int> true_people;
int adj[51][51];
bool truth[51];
bool visited[51];
int ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    ans = m;
    int k;
    cin >> k;
    for(int i=0; i<k; i++) {
        int a;
        cin >> a;
        true_people.push(a);
    }
    for(int i=1; i<=m; i++) {
        cin >> k;
        for(int j=0; j<k; j++) {
            int a;
            cin >> a;
            adj[i][a] = 1;
        }
    }

    while(!true_people.empty()) {
        int p = true_people.front();
        true_people.pop();
        if(visited[p])
            continue;
        visited[p] = true;
        for(int i=1; i<=m; i++) {
            if(adj[i][p] == 1 && !truth[i]) {
                truth[i] = true;
                ans--;
                for(int j=1; j<=n; j++) {
                    if(adj[i][j] == 1 && !visited[j]) {
                        true_people.push(j);
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}