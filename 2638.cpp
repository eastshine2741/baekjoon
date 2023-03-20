#include <iostream>
#include <queue>
using namespace std;

int grid[101][101];
int n,m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

bool isSafe(int x, int y) {
    return x>=0 && y>=0 && x<m && y<n;
}

void find_air() {
    queue<pair<int, int>> q;
    bool visited[101][101] = {false,};
    q.push(make_pair(0,0));
    grid[0][0] = -1;
    while(!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();
        visited[cur.second][cur.first] = true;
        for(int i=0; i<4; i++) {
            if(isSafe(cur.first+dx[i], cur.second+dy[i]) && !visited[cur.second+dy[i]][cur.first+dx[i]] && grid[cur.second+dy[i]][cur.first+dx[i]] == 0) {
                grid[cur.second+dy[i]][cur.first+dx[i]] = -1;
                q.push(make_pair(cur.first+dx[i], cur.second+dy[i]));
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }

    find_air();

    int t = 0;
    while(true) {
        queue<pair<int,int>> q;
        queue<pair<int,int>> tq;
        bool visited[101][101] = {false,};
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    int cnt = 0;
                    for(int k=0; k<4; k++) {
                        if(isSafe(j+dx[k], i+dy[k]) && grid[i+dy[k]][j+dx[k]] == -1) {
                            cnt++;
                        }
                    }
                    if(cnt>=2) {
                        q.push(make_pair(j,i));
                        tq.push(make_pair(j, i));
                        while(!tq.empty()) {
                            pair<int,int> cur = tq.front(); tq.pop();
                            if(visited[cur.second][cur.first])
                                continue;
                            visited[cur.second][cur.first] = true;
                            for(int l=0; l<4; l++) {
                                int nx = cur.first + dx[l];
                                int ny = cur.second + dy[l];
                                if(isSafe(nx, ny) && !visited[ny][nx] && grid[ny][nx] == 0) {
                                    q.push(make_pair(nx, ny));
                                    tq.push(make_pair(nx, ny));
                                }
                            }
                        }
                    }
                }
            }
        }
        if(q.empty())
            break;
        while(!q.empty()) {
            pair<int,int> cur = q.front();
            q.pop();
            grid[cur.second][cur.first] = -1;
        }
        t++;
    }
    cout << t;
    return 0;
}