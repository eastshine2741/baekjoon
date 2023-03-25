#include <iostream>
#include <vector>
using namespace std;

void boom(vector<char>& stack, string explode) {
    if(stack.size() < explode.size())
        return;
    auto it1 = stack.rbegin();
    auto it2 = explode.rbegin();
    while(it1 != stack.rend() && it2 != explode.rend()) {
        if(*it1 != *it2) {
            return;
        }
        it1++; it2++;
    }
    for(int i=0; i<explode.size(); i++)
        stack.pop_back();
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str, explode;
    cin >> str;
    cin >> explode;

    vector<char> stack;
    for(char c: str) {
        stack.push_back(c);
        if(c == explode.back()) {
            boom(stack, explode);
        }
    }
    if(stack.empty()) {
        cout << "FRULA";
    }
    else {
        for(char c: stack) {
            cout << c;
        }
    }
    return 0;
}