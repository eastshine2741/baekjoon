#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    vector<int> ans;
    cin >> t;
    for(int i=0; i<t; i++) {
        int a,b;
        cin >> a >> b;
        int x = b-a;
        int k = sqrt(x);
        ans.push_back(2*(k)-1+ceil((x-k*k)/(double)k));
    }
    for(int a : ans) {
        cout << a << "\n";
    }
    return 0;
}