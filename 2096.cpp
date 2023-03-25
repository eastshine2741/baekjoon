#include <iostream>
using namespace std;

int max(int a, int b) {
    return (a>b) ? a : b;
}

int max(int a, int b, int c) {
    int m = (a>b) ? a : b;
    m = (m>c) ? m : c;
    return m;
}

int min(int a, int b) {
    return (a<b) ? a : b;
}

int min(int a, int b, int c) {
    int min = (a<b) ? a : b;
    min = (min<c) ? min : c;
    return min;
}


int n;
int arr[100001][3];
int dp[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    dp[0] = arr[0][0];
    dp[1] = arr[0][1];
    dp[2] = arr[0][2];
    for(int i=1; i<n; i++) {
        int temp_dp[3];
        temp_dp[0] = max(dp[0], dp[1]) + arr[i][0];
        temp_dp[1] = max(dp[0], dp[1], dp[2]) + arr[i][1];
        temp_dp[2] = max(dp[1], dp[2]) + arr[i][2];
        dp[0] = temp_dp[0];
        dp[1] = temp_dp[1];
        dp[2] = temp_dp[2];
    }
    int ans1 = max(dp[0], dp[1], dp[2]);

    dp[0] = arr[0][0];
    dp[1] = arr[0][1];
    dp[2] = arr[0][2];
    for(int i=1; i<n; i++) {
        int temp_dp[3];
        temp_dp[0] = min(dp[0], dp[1]) + arr[i][0];
        temp_dp[1] = min(dp[0], dp[1], dp[2]) + arr[i][1];
        temp_dp[2] = min(dp[1], dp[2]) + arr[i][2];
        dp[0] = temp_dp[0];
        dp[1] = temp_dp[1];
        dp[2] = temp_dp[2];
    }
    int ans2 = min(dp[0], dp[1], dp[2]);
    cout << ans1 << " " << ans2;
    return 0;
}
