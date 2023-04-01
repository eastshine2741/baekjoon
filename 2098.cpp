#include <iostream>
#define INF 1e9
using namespace std;

int n;
int finish;
int adj[17][17];
int dp[17][1<<17];

int tsp(int cur, int visited) {
    if(visited == finish) {
        if(adj[cur][1] > 0) {
            return adj[cur][1];
        }
        return INF;
    }

    if(dp[cur][visited] != 0)
        return dp[cur][visited];

    int min = INF;
    for(int i=1; i<=n; i++) {
        if(adj[cur][i] > 0 && (visited & (1<<i)) == 0) {
            int t = adj[cur][i] + tsp(i, visited | (1<<i));
            if(t < min) min = t;
        }
    }
    dp[cur][visited] = min;
    return min;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    fill(&dp[0][0], &dp[16][(1<<17)-1], INF);
//    dp[1][1<<1] = 0;

    cin >> n;
    for(int i=1; i<=n; i++) {
        finish |= 1 << i;
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> adj[i][j];
        }
    }

    cout << tsp(1, 1<<1);


    return 0;
}