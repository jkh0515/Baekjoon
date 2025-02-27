//15678 연세워터파크 - C++17
//메모리 : 3744KB / 시간 : 16ms
//2024년 7월 8일 00:54:34

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    deque<pair<int, long long>> dq;
    int i, n, d;
    long long ans = -1e9, t;
    cin >> n >> d;
    for(i=1;i<=n;i++) {
        cin >> t;
        while(!dq.empty() and dq.front().first < i - d) dq.pop_front();
        if(!dq.empty()) t += max(0LL, dq.front().second);
        ans = max(ans, t);
        while(!dq.empty() and dq.back().second < t) dq.pop_back();
        dq.push_back({i, t});
    }
    cout << ans;
    return 0;
}