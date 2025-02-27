//1389 케빈 베이컨의 6단계 법칙 - C++17
//메모리 : 2024KB / 시간 : 0ms
//2024년 5월 9일 00:47:34

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int dp[101][101], n, m, a, b, i, j, p = 0, pa = 1e9;
    vector<int> fr[101];
    cin >> n >> m;
    fill(&dp[0][0], &dp[100][101], -1e9);
    while(m--) {
        cin >> a >> b;
        // if(dp[a][b] == -1e9) {
            fr[a].push_back(b);
            fr[b].push_back(a);
        //     dp[a][b] = -1;
        //     dp[b][a] = -1;
        // }
    }
    for(i=1;i<=n;i++) {
        priority_queue<pair<int, int>> pq;
        pq.push({0, i});
        int ans = 0;
        while(!pq.empty()) {
            int d = pq.top().first;
            int f = pq.top().second;
            pq.pop();
            if(dp[i][f] > d) continue;
            for(j=0;j<fr[f].size();j++) {
                int td = d-1;
                int tf = fr[f][j];
                if(dp[i][tf] < td) {
                    dp[i][tf] = td;
                    pq.push({td, tf});
                }
            }
        }
        for(j=1;j<=n;j++)
            ans -= dp[i][j];
        if(pa > ans) {
            pa = ans;
            p = i;
        }
    }
    cout << p;
    return 0;
}