#include <iostream>
#include <vector>
using namespace std;


class Tetromino {
public:
    int h, w;
    vector<vector<int>>* vect;
    Tetromino(int height, int width, vector<vector<int>>* vector) {
        h = height;
        w = width;
        vect = vector;
    }
    ~Tetromino() {
        delete vect;
    }
};

vector<Tetromino>* tetrominos;
int n, m;
int 

void initialize() {
    tetrominos = new vector<Tetromino> {
            Tetromino(1, 4, new vector<vector<int>>{
                    {1,1,1,1}
            }),
            Tetromino(4, 1, new vector<vector<int>>{
                    {1},
                    {1},
                    {1},
                    {1}
            }),
            Tetromino(2, 2, new vector<vector<int>>{
                    {1, 1},
                    {1, 1}
            }),
            Tetromino(2, 3, new vector<vector<int>>{
                    {1, 1, 1},
                    {1, 0, 0}
            }),
            Tetromino(3, 2, new vector<vector<int>>{
                    {1, 1},
                    {0, 1},
                    {0, 1}
            }),
            Tetromino(2, 3, new vector<vector<int>>{
                    {0, 0, 1},
                    {1, 1, 1}
            }),
            Tetromino(3, 2, new vector<vector<int>>{
                    {1, 0},
                    {1, 0},
                    {1, 1}
            }),
            Tetromino(2, 3, new vector<vector<int>>{
                    {1, 0, 0},
                    {1, 1, 1}
            }),
            Tetromino(3, 2, new vector<vector<int>>{
                    {1, 1},
                    {1, 0},
                    {1, 0}
            }),
            Tetromino(2, 3, new vector<vector<int>>{
                    {1, 1, 1},
                    {0, 0, 1}
            }),
            Tetromino(3, 2, new vector<vector<int>>{
                    {0, 1},
                    {0, 1},
                    {1, 1}
            }),
            Tetromino(3, 2, new vector<vector<int>>{
                    {1, 0},
                    {1, 1},
                    {0, 1}
            }),
            Tetromino(2, 3, new vector<vector<int>>{
                    {0, 1, 1},
                    {1, 1, 0}
            }),
            Tetromino(3, 2, new vector<vector<int>>{
                    {0, 1},
                    {1, 1},
                    {1, 0}
            }),
            Tetromino(2, 3, new vector<vector<int>>{
                    {1, 1, 0},
                    {0, 1, 1}
            }),
            Tetromino(2, 3, new vector<vector<int>>{
                    {1, 1, 1},
                    {0, 1, 0}
            }),
            Tetromino(3, 2, new vector<vector<int>>{
                    {0, 1},
                    {1, 1},
                    {0, 1}
            }),
            Tetromino(2, 3, new vector<vector<int>>{
                    {0, 1, 0},
                    {1, 1, 1}
            }),
            Tetromino(3, 2, new vector<vector<int>>{
                    {1, 0},
                    {1, 1},
                    {1, 0}
            })
    };
}

void input() {

}

void solve() {

}

int main() {
    initialize();
    input();

    delete tetrominos;
    return 0;
}