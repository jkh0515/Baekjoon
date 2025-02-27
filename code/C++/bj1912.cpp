//1912 연속합 - C++17
//메모리 : 2020KB / 시간 : 4ms
//2024년 6월 19일 01:28:50

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ans = -1e9, i, n, t, w = -1e9;
    cin >> n;
    for(i=0;i<n;i++) {
        cin >> t;
        w = max(w + t, t);
        ans = max(ans, w);
    }
    cout << ans;
    return 0;
}