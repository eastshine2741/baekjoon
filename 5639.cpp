#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> preorder;
vector<int> inorder;

void solve(int n, int ps, int is) {
    if(n==0) {
        return;
    }
    else if(n==1) {
        cout << preorder[ps] << " ";
        return;
    }
    int root = preorder[ps];
    int root_idx_in = find(inorder.begin(), inorder.end(), root) - inorder.begin();
    solve(root_idx_in-is, ps+1, is);
    solve(n-(root_idx_in-is)-1, ps+1+root_idx_in-is, is+root_idx_in-is+1);
    cout << root << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a;
    int n=0;
    while(cin >> a) {
        if(a == -1)
            break;
        preorder.push_back(a);
        inorder.push_back(a);
        n++;
    }
    sort(inorder.begin(), inorder.end());
    solve(n, 0, 0);


    return 0;
}