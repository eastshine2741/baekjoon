#include <iostream>
#include <deque>
#include <sstream>
#include <vector>
using namespace std;

deque<int> getDeque(string sarr) {
    sarr.pop_back();
    sarr.erase(0, 1);
    stringstream ss(sarr);
    string temp;
    deque<int> res;
    while(getline(ss, temp, ',')) {
        res.push_back(stoi(temp));
    }
    return res;
}

void solve(string func, string sarr) {
    deque<int> deq = getDeque(sarr);
    bool asc = true;
    for(char c : func) {
        if(c == 'R') {
            asc = !asc;
        }
        else if(c == 'D') {
            if(deq.empty()) {
                cout << "error" << endl;
                return;
            }
            if(asc) {
                deq.pop_front();
            }
            else {
                deq.pop_back();
            }
        }
    }
    vector<int> res;
    while(!deq.empty()) {
        if(asc) {
            res.push_back(deq.front());
            deq.pop_front();
        }
        else {
            res.push_back(deq.back());
            deq.pop_back();
        }
    }
    cout << "[";
    if(!res.empty()) {
        for (auto it = res.begin(); it != res.end() - 1; it++) {
            cout << *it << ",";
        }
        cout << res.back();
    }
    cout << "]" << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        string func;
        int n;
        string sarr;
        cin >> func;
        cin >> n;
        cin >> sarr;

        solve(func, sarr);
    }
    return 0;
}