#include <iostream>
#include <vector>
using namespace std;

bool solve(string s) {
    vector<char> stack;
    for(char c: s) {
        if(c == '(') {
            stack.push_back(c);
        }
        else if(c == ')') {
            if(stack.empty())
                return false;
            char c2 = stack.back();
            stack.pop_back();
            if(c2 != '(')
                return false;
        }
    }
    if(!stack.empty())
        return false;
    else
        return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        string s;
        cin >> s;
        if(solve(s))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}