#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007LL
typedef unsigned long long LONG;

struct Matrix2 {
    vector<vector<LONG>>* mat;

    Matrix2() {
        mat = new vector<vector<LONG>>;
        mat->resize(2, vector<LONG>(2));
    }

    Matrix2(LONG a11, LONG a12, LONG a21, LONG a22) {
        mat = new vector<vector<LONG>>;
        mat->resize(2, vector<LONG>(2));
        (*mat)[0][0] = a11;
        (*mat)[0][1] = a12;
        (*mat)[1][0] = a21;
        (*mat)[1][1] = a22;
    }

    Matrix2 operator*(const Matrix2& other) {
        Matrix2 res;
        for(int i=0; i<2; i++) {
            for(int j=0; j<2; j++) {
                (*res.mat)[i][j]=0;
                for(int k=0; k<2; k++) {
                    (*res.mat)[i][j] = ((*res.mat)[i][j]%MOD + ((*this->mat)[i][k]%MOD * (*other.mat)[k][j]%MOD)%MOD)%MOD;
//                    (*res.mat)[i][j] += (*this->mat)[i][k] * (*other.mat)[k][j];
                }
//                (*res.mat)[i][j] %= MOD;
            }
        }
        return res;
    }

    ~Matrix2() {
        delete mat;
    }
};

Matrix2 pow(LONG n) {
    if(n==1) {
        return Matrix2(1, 1, 1, 0);
    }
    if(n%2 == 0) {
        Matrix2 p = pow(n/2);
        return p*p;
    }
    else {
        Matrix2 p = pow((n-1)/2);
        return p*p*pow(1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    LONG n;
    cin >> n;
    if(n == 0) {
        cout << 0;
    }
    else {
        Matrix2 m = pow(n);
        cout << m.mat->at(0)[1];
    }

    return 0;
}