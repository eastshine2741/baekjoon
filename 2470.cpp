//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int n;
//int arr[100001];
//
//int find_similar(int x) {
//    int s = 1;
//    int e = n;
//    while(s<e) {
//        int m = (s+e)/2;
//        if(arr[m] == x)
//            return m;
//        if(arr[m] < x)
//            s = m+1;
//        else
//            e = m-1;
//    }
//    if(abs(arr[e]-x) < abs(arr[s]-x))
//        return e;
//    else
//        return s;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    int min = 0x7fffffff;
//    int a, b;
//    cin >> n;
//    for(int i=1; i<=n; i++) {
//        cin >> arr[i];
//    }
//    sort(arr+1, arr+n+1);
//    for(int i=1; i<=n; i++) {
//        if(arr[i] == 0)
//            continue;
//        int idx = find_similar(-arr[i]);
//        if(abs(min) > abs(arr[i] + arr[idx])) {
//            min = arr[i] + arr[idx];
//            if(i < idx) {
//                a = i;
//                b = idx;
//            }
//            else {
//                a = idx;
//                b = i;
//            }
//        }
//    }
//    cout << arr[a] << " " << arr[b];
//    return 0;
//}

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int arr[100001];
    int min = 0x7fffffff;
    int min_a, min_b;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int s=0, e=n-1;
    while(s<e) {
        int sum = arr[s] + arr[e];
        if(abs(min) > abs(sum)) {
            min = sum;
            min_a = arr[s];
            min_b = arr[e];
        }
        if(sum == 0) {
            break;
        }
        else if(sum < 0) {
            s++;
        }
        else {
            e--;
        }
    }
    cout << min_a << " " << min_b;
    return 0;
}