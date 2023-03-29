#include <iostream>
#include <vector>
using namespace std;

int n;
int e;
vector<int> tree[51];

int dfs(int x) {
    if(x == e)
        return 0;
    if(tree[x].empty())
        return 1;

    int res = 0;
    for(int c : tree[x]) {
        if(c == e && tree[x].size() == 1)
            return 1;
        res += dfs(c);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r;
    cin >> n;
    for(int i=0; i<n; i++) {
        int p;
        cin >> p;
        if(p == -1) {
            r = i;
        }
        else {
            tree[p].push_back(i);
        }
    }

    cin >> e;
    cout << dfs(r);

    return 0;
}