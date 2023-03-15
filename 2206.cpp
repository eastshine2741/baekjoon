#include <iostream>
#include <queue>
#include <deque>
using namespace std;

struct Node {
    int x, y;
    int dist;
    bool broke;

    Node(int x, int y, int dist, bool broke): x(x), y(y), dist(dist), broke(broke) {}
};

int n,m;
int matrix[1001][1001];
int visited[1001][1001];
queue<Node> q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

bool isSafe(int x, int y) {
    return x>=1 && x<=m && y>=1 && y<=n;
}

int solve() {
    if(matrix[1][1] == 0)
        q.push(Node(1, 1, 1, false));
    else
        q.push(Node(1, 1, 1, true));
    while(!q.empty()) {
        Node cur = q.front();
        q.pop();
        if(cur.broke && (visited[cur.y][cur.x] & 0x00000010)>0 || !cur.broke && (visited[cur.y][cur.x] & 0x00000001)>0)
            continue;
        if(cur.x == m && cur.y == n) {
            return cur.dist;
        }
        if(cur.broke)
            visited[cur.y][cur.x] |= 0x00000010;
        else
            visited[cur.y][cur.x] |= 0x00000001;
        for(int i=0; i<4; i++) {
            int nx = cur.x+dx[i];
            int ny = cur.y+dy[i];
            if(isSafe(nx, ny)) {
                if(cur.broke && (visited[ny][nx] & 0x00000010) == 0) {
                    if (matrix[ny][nx] == 0) {
                        q.push(Node(nx, ny, cur.dist + 1, cur.broke));
                    }
                }
                else if(!cur.broke && (visited[ny][nx] & 0x00000001) == 0) {
                    if(matrix[ny][nx] == 1) {
                        q.push(Node(nx, ny, cur.dist+1, true));
                    }
                    else {
                        q.push(Node(nx, ny, cur.dist+1, cur.broke));
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        string s;
        cin >> s;
        for(int j=1; j<=m; j++) {
            matrix[i][j] = s.at(j-1)-48;
        }
    }
    cout << solve();

    return 0;
}