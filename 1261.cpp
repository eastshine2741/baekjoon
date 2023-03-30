#include <iostream>
#include <queue>
using namespace std;

struct node {
    int walls;
    int x;
    int y;

    node(int x, int y, int walls): x(x), y(y), walls(walls) {}
    bool operator<(const node& other) const {
        return this->walls > other.walls;
    }
};

int n,m;
int mat[101][101];
int visited[101][101];
priority_queue<node> pq;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool isSafe(int x, int y) {
    return x>=1 && x<=m && y>=1 && y<=n;
}

bool getVisited(int x, int y, int wall) {
    return (visited[y][x] & (1 << wall)) != 0;
}

void setVisited(int x, int y, int wall) {
    visited[y][x] |= (1 << wall);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;
    for(int i=1; i<=n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<m; j++) {
            mat[i][j+1] = s[j] - 48;
        }
    }

    pq.push(node(1, 1, 0));
    while(!pq.empty()) {
        node cur = pq.top(); pq.pop();
        if(cur.x == m && cur.y == n) {
            cout << cur.walls;
            break;
        }
        if(getVisited(cur.x, cur.y, cur.walls))
            continue;
        setVisited(cur.x, cur.y, cur.walls);
        for(int i=0; i<4; i++) {
            int nx = cur.x+dx[i];
            int ny = cur.y+dy[i];
            if(isSafe(nx, ny)) {
                if(mat[ny][nx] == 0) {
                    if(visited[ny][nx] == 0) {
                        pq.push(node(nx, ny, cur.walls));
                    }
                }
                else {
                    if(!getVisited(nx, ny, cur.walls+1)) {
                        pq.push(node(nx, ny, cur.walls + 1));
                    }
                }
            }
            if(isSafe(nx, ny) && !getVisited(nx, ny, mat[ny][nx] == 1 ? cur.walls+1 : cur.walls)) {
                pq.push(node(nx, ny, mat[ny][nx] == 1 ? cur.walls+1 : cur.walls));
            }
        }
    }

    return 0;
}