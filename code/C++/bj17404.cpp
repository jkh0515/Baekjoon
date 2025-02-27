//17404 RGB거리 2 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 3월 17일 21:31:04

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, i, j, ans = -1e9, arr[1000][3], dp[3][1000][3];
    fill(&dp[0][0][0], &dp[2][999][3], -1e9);
    priority_queue<pair<pair<int, int>, pair<int, int>>> pq;
    cin >> n;
    for(i=0;i<n;i++)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    for(i=0;i<3;i++) {
        for(j=0;j<3;j++) {
            if(i == j) continue;
            pq.push({{arr[0][i] * -1, 0}, {i, i}});
            dp[i][0][i] = 0;
        }
    }
    while(!pq.empty()) {
        int w = pq.top().first.first;
        int idx = pq.top().first.second;
        int p = pq.top().second.first;
        int s = pq.top().second.second;
        pq.pop();
        // cout << w << " " << idx << " " << p << " " << s << endl;
        if(dp[s][idx][p] < w) continue;
        if(idx == n - 2) {
            for(i=0;i<3;i++) {
                if(i == s or i == p) continue;
                ans = max(ans, w - arr[idx+1][i]);
            }
            continue;
        }
        for(i=0;i<3;i++) {
            if(i == p) continue;
            int tw = w - arr[idx+1][i];
            if(dp[s][idx+1][i] < tw) {
                dp[s][idx+1][i] = tw;
                pq.push({{tw, idx+1},{i, s}});
            }
        }
    }
    cout << ans * -1;
    return 0;
}