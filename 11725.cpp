#include <iostream>
#include <vector>
#define MAX_SIZE 100001
using namespace std;

int n;
vector<int> tree[MAX_SIZE];
int ans[MAX_SIZE];

void find_parent(int node, int from) {
    for(int child : tree[node]) {
        if(child != from) {
            ans[child] = node;
            find_parent(child, node);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    find_parent(1, 0);
    for(int i=2; i<=n; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}