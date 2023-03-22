#include <iostream>
using namespace std;
typedef long long LONG;

int CCW(LONG x1, LONG y1, LONG x2, LONG y2) {
    LONG cross = x1*y2 - x2*y1;
    if(cross==0) {
        return 0;
    }
    else if(cross > 0) {
        return 1;
    }
    else {
        return -1;
    }
}

void swap(LONG* x1, LONG* x2) {
    LONG temp = *x1;
    *x1 = *x2;
    *x2 = temp;
}

int overlap(LONG x1, LONG x2, LONG x3, LONG x4) {
    if(x1>x2)
        swap(&x1, &x2);
    if(x3>x4)
        swap(&x3, &x4);
//    if(abs(x4-x1) <= abs(x2-x1)+abs(x4-x3))
//        return 1;
//    else
//        return 0;
    if(x1<=x4 && x2>=x3)
        return 1;
    else
        return 0;
}

bool isOnLine(LONG x1, LONG y1, LONG x2, LONG y2, LONG x3, LONG y3) {
    if(CCW(x2-x1, y2-y1, x3-x1, y3-y1) == 0 && (x1-x3)*(x2-x3) < 0 && (y1-y3)*(y2-y3) < 0) {
        return true;
    }
    else {
        return false;
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

    int m = CCW(x2-x1, y2-y1, x3-x1, y3-y1) * CCW(x2-x1, y2-y1, x4-x1, y4-y1);
    int n = CCW(x4-x3, y4-y3, x1-x3, y1-y3) * CCW(x4-x3, y4-y3, x2-x3, y2-y3);
//    if(m<0 && n<0) {
//        cout << 1;
//    }
//    else if(m == 0 && n == 0) {
//        if(overlap(x1, x2, x3, x4) == 1 && overlap(y1, y2, y3, y4) == 1)
//            cout << 1;
//        else
//            cout << 0;
//    }
//    else if(m == 0) {
//        if(isOnLine(x1, y1, x2, y2, x3, y3) || isOnLine(x1, y1, x2, y2, x4, y4))
//            cout << 1;
//        else
//            cout << 0;
//    }
//    else if(n == 0) {
//        if(isOnLine(x3, y3, x4, y4, x1, y1) || isOnLine(x3, y3, x4, y4, x2, y2))
//            cout << 1;
//        else
//            cout << 0;
//    }
//    else {
//        cout << 0;
//    }

    if(m == 0 && n == 0) {
        if(overlap(x1, x2, x3, x4) == 1 && overlap(y1, y2, y3, y4) == 1)
            cout << 1;
        else
            cout << 0;
    }
    else if(m <= 0 && n <= 0) {
        cout << 1;
    }
    else {
        cout << 0;
    }

    return 0;
}