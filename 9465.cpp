#include <iostream>
using namespace std;

int ans[100001];

int solve() {
    int n;
    int v[2][100001];
    int dp[2][100001] = {0,};
    int res;
    cin >> n;
    for(int i=0; i<2; i++) {
        for(int j=1; j<=n; j++) {
            cin >> v[i][j];
        }
    }

    dp[0][1] = v[0][1];
    dp[1][1] = v[1][1];
    res = max(dp[0][1], dp[1][1]);
    for(int j=2; j<=n; j++) {
        for(int i=0; i<2; i++) {
            dp[i][j] = max(dp[1-i][j-2], dp[1-i][j-1]) + v[i][j];
            if(res < dp[i][j])
                res = dp[i][j];
        }
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        ans[i] = solve();
    }
    for(int i=0; i<t; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}