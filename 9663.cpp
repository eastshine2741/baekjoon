#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
    Point(int x, int y): x(x), y(y) {}
};

int n;
int ans = 0;

int abs(int a) {
    if(a < 0)
        return -a;
    else
        return a;
}

bool possible(vector<Point>& points, int x, int y) {
    for(Point point: points) {
        if(point.x == x || point.y == y || abs(point.x - x) == abs(point.y - y))
            return false;
    }
    return true;
}

void solve(vector<Point>& points, int row) {
    if(row == n) {
        if(!points.empty())
            ans++;
        return;
    }
    for(int i=0; i<n; i++) {
        if(possible(points, i, row)) {
            points.emplace_back(i, row);
            solve(points, row+1);
            points.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    vector<Point> points;
    solve(points, 0);
    cout << ans;

    return 0;
}