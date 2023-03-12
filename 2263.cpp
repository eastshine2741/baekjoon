#include <iostream>
#include <algorithm>
using namespace std;

int in_order[100001];
int post_order[100001];

void solve(int n, int is, int ps) {
    int root = post_order[ps+n-1];
    cout << root << " ";
    int root_idx = find(in_order+is, in_order+is+n, root) - (in_order+is);
    if(root_idx > 0) {
        solve(root_idx, is, ps);
    }
    if(root_idx < n-1) {
        solve(n-root_idx-1, is+root_idx+1, ps+root_idx);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> in_order[i];
    }
    for(int i=0; i<n; i++) {
        cin >> post_order[i];
    }

    solve(n, 0, 0);

    return 0;
}