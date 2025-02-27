//11497 통나무 건너뛰기 - C++17
//메모리 : 2160KB / 시간 : 48ms
//2024년 7월 30일 23:26:30

#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int i, n, a, ans = 0;
        priority_queue<int> pq;
        deque<int> dq;
        cin >> n;
        for(i=0;i<n;i++) {
            cin >> a;
            pq.push(a);
        }
        for(i=0;i<n;i++) {
            if(i % 2 == 0) dq.push_front(pq.top());
            else dq.push_back(pq.top());
            pq.pop();
        }
        dq.push_front(dq.back());
        for(i=1;i<=n;i++) {
            // cout << dq[i-1] << " ";
            ans = max(ans, abs(dq[i] - dq[i-1]));
        }
        // cout << endl;
        cout << ans << "\n"; 
    }
    return 0;
}