#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int arr[10];

void dfs(int depth, vector<int>& indices) {
    if(depth == m) {
        for(int i : indices) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    bool visited[10001] = {false,};
    for(int i=1; i<=n; i++) {
        if(find(indices.begin(), indices.end(), i) != indices.end())
            continue;
        if(visited[arr[i]])
            continue;
        visited[arr[i]] = true;
        indices.push_back(i);
        dfs(depth+1, indices);
        indices.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n+1);
    vector<int> indices;
    dfs(0, indices);

    return 0;
}