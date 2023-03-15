#include <iostream>
using namespace std;

int tri[501][501];
int dp[501][501];

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            cin >> tri[i][j];
        }
    }
    for(int i=n-1; i>=0; i--) {
        for(int j=0; j<=i; j++) {
            dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + tri[i][j];
        }
    }
    cout << dp[0][0];
    return 0;
}