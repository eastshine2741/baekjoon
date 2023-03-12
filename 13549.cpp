#include <iostream>
#include <queue>
#define MAX_SIZE 100001
using namespace std;

struct Data{
    int idx;
    int time;
    Data(int idx, int time): idx(idx), time(time) {}

    bool operator<(const Data d) const{
        return this->time > d.time;
    }
};

int n,k;
int arr[MAX_SIZE];
priority_queue<Data> pqueue;

int main() {
    fill_n(arr, MAX_SIZE, 0x7fffffff);
    cin >> n >> k;

    pqueue.push(Data(n, 0));
    while(!pqueue.empty()) {
        Data cur = pqueue.top();
        pqueue.pop();
        if(cur.time >= arr[cur.idx])
            continue;
        arr[cur.idx] = cur.time;
        if(cur.idx > 0)
            pqueue.push(Data(cur.idx-1, cur.time+1));
        if(cur.idx < MAX_SIZE - 1)
            pqueue.push(Data(cur.idx+1, cur.time+1));
        if(cur.idx*2 < MAX_SIZE)
            pqueue.push(Data(cur.idx*2, cur.time+1));
    }
    cout << arr[k];
    return 0;
}