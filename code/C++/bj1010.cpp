//1010 다리 놓기 - C++17
//메모리 : 2028KB / 시간 : 0ms
//2024년 7월 13일 00:50:41

#include <iostream>
#include <algorithm>
using namespace std;

long arr[31][31];

long cal(int a, int b) {
    if(arr[a][b] != 0) return arr[a][b];
    if(a == b or b == 0) return 1;
    return arr[a][b] = cal(a - 1, b - 1) + cal(a - 1, b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t, n, m;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        cout << cal(m, n) << "\n";
    }
    return 0;
}