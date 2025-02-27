//13975 파일 합치기 3 - C++17
//메모리 : 18532KB / 시간 : 728ms
//2024년 7월 20일 23:26:38

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long lli;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int k;
        lli n, ans = 0;
        priority_queue<lli, vector<lli>, greater<lli>> pq;
        cin >> k;
        while(k--) {
            cin >> n;
            pq.push(n);
        }
        n = pq.top();
        pq.pop();
        do {
            ans += n + pq.top();
            pq.push(n + pq.top());
            pq.pop();
            n = pq.top();
            pq.pop();
        } while(!pq.empty());
        cout << ans << "\n";
    }
    return 0;
}