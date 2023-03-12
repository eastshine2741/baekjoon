#include <iostream>
#include <queue>
using namespace std;

#define MAX_SIZE 100001
bool visited[MAX_SIZE];

int main() {
    int n,k;
    int ways = 0;
    int dist = 0x7fffffff;
    queue<pair<int,int>> q;
    cin >> n >> k;

    q.push(pair<int, int>(n, 0));
    while(!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();
        visited[cur.first] = true;

        if(cur.first == k) {
            if(cur.second > dist)
                break;
            dist = cur.second;
            ways++;
        }
        if(cur.first < MAX_SIZE - 1 && !visited[cur.first+1])
            q.push(pair<int,int>(cur.first+1, cur.second+1));
        if(cur.first > 0 && !visited[cur.first-1])
            q.push(pair<int,int>(cur.first-1, cur.second+1));
        if(cur.first*2 < MAX_SIZE && !visited[cur.first*2])
            q.push(pair<int,int>(cur.first*2, cur.second+1));
    }
    cout << dist << endl;
    cout << ways;
    return 0;
}