#include <iostream>
#include <vector>
#define MOD 1000LL
using namespace std;

typedef unsigned long long LONG;
typedef vector<vector<LONG>> matrix;

matrix operator*(const matrix& A, const matrix& B) {
    matrix res(A.size(), vector<LONG>(B[0].size()));
    for(int i=0; i<A.size(); i++) {
        for(int j=0; j<B[0].size(); j++) {
            for(int k=0; k<B.size(); k++) {
                res[i][j] = (res[i][j]%MOD + ((A[i][k]%MOD) * (B[k][j]%MOD))%MOD)%MOD;
//                res[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return res;
}

matrix pow(matrix& m, LONG b) {
    if(b == 1) {
        for(int i=0; i<m.size(); i++) {
            for(int j=0; j<m[0].size(); j++) {
                m[i][j] %= MOD;
            }
        }
        return m;
    }
    if(b%2==0) {
        matrix p = pow(m, b/2);
        return p*p;
    }
    else {
        matrix p = pow(m, (b-1)/2);
        return p*p*pow(m, 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    LONG b;
    cin >> n;
    cin >> b;
    matrix m(n, vector<LONG>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> m[i][j];
        }
    }
    matrix res = pow(m, b);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}