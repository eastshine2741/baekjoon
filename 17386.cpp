#include <iostream>
using namespace std;
typedef long long LONG;

int CCW(LONG x1, LONG y1, LONG x2, LONG y2) {
    LONG cross = x1*y2 - x2*y1;
    if(cross>0) {
        return 1;
    }
    else {
        return -1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    LONG x1, x2, y1, y2;
    LONG x3, x4, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    if(CCW(x2-x1, y2-y1, x3-x1, y3-y1) * CCW(x2-x1, y2-y1, x4-x1, y4-y1) < 0
    && CCW(x4-x3, y4-y3, x1-x3, y1-y3) * CCW(x4-x3, y4-y3, x2-x3, y2-y3) < 0)
        cout << 1;
    else
        cout << 0;

    return 0;
}