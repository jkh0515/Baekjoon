//14863 서울에서 경산까지 - C++17
//메모리 : 41868KB / 시간 : 28ms
//2024년 3월 30일 01:24:04

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, k, i, ans, arr[102][4], dp[102][100001];

int main() {
    cin >> n >> k;
    priority_queue<pair<int, pair<int, int>>> pq;
    for(i=1;i<=n;i++)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
    pq.push({1, {0, 0}});
    fill(&dp[0][0], &dp[101][100001], -1);
    while(!pq.empty()) {
        int idx = pq.top().first;
        int money = pq.top().second.first;
        int dtime = pq.top().second.second;
        // cout << idx << " " << money << " " << dtime << endl;
        pq.pop();
        if(dtime > k or dp[idx][dtime] > money) continue;
        if(idx == n+1) {
            ans = max(ans, money);
            continue;
        }
        int tdtime = dtime + arr[idx][0], tmoney = money + arr[idx][1];
        if(tdtime <= k and dp[idx+1][tdtime] < tmoney) {
            dp[idx+1][tdtime] = tmoney;
            pq.push({idx+1, {tmoney, tdtime}});
        }
        tdtime = dtime + arr[idx][2], tmoney = money + arr[idx][3];
        if(tdtime <= k and dp[idx+1][tdtime] < tmoney) {
            dp[idx+1][tdtime] = tmoney;
            pq.push({idx+1, {tmoney, tdtime}});
        }
    }
    cout << ans;
    return 0;
}