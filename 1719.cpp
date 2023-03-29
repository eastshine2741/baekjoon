#include <iostream>
#define INF 987654321
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    int adj[201][201];
    int table[201][201];
    cin >> n >> m;
    fill(&adj[0][0], &adj[200][201], INF);
    fill(&table[0][0], &table[200][201], 0);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i!=j)
                table[i][j] = j;
        }
    }
    for(int i=1; i<=n; i++) {
        adj[i][i] = 0;
    }
    for(int i=0; i<m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a][b] = c;
        adj[b][a] = c;
    }
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(adj[i][j] > adj[i][k]+adj[k][j]) {
                    adj[i][j] = adj[i][k]+adj[k][j];
                    table[i][j] = table[i][k];
                }
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(table[i][j] == 0)
                cout << "- ";
            else
                cout << table[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}