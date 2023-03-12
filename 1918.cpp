#include <iostream>
#include <vector>
using namespace std;

int priority(char op) {
    if(op == '+' || op == '-') {
        return 1;
    }
    else if(op == '*' || op == '/') {
        return 2;
    }
    else if(op == '(') {
        return 0;
    }
    else if(op == ')') {
        return 3;
    }
    else {
        return -1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string eq;
    vector<char> stack;
    cin >> eq;
    for(char c : eq) {
        switch(priority(c)) {
            case -1:
                cout << c;
                break;
            case 3:
                while(!stack.empty() && stack.back() != '(') {
                    cout << stack.back();
                    stack.pop_back();
                }
                stack.pop_back();
                break;
            case 0:
                stack.push_back(c);
                break;
            default:
                if(!stack.empty() && priority(stack.back()) >= priority(c)) {
                    while(!stack.empty() && priority(stack.back()) >= priority(c)) {
                        cout << stack.back();
                        stack.pop_back();
                    }
                    stack.push_back(c);
                }
                else {
                    stack.push_back(c);
                }
                break;
        }
    }
    while(!stack.empty()) {
        cout << stack.back();
        stack.pop_back();
    }
    return 0;
}