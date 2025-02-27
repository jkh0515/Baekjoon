//6118 숨바꼭질 - C++17
//메모리 : 3848KB / 시간 : 16ms
//2024년 5월 4일 16:06:36

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, i, a, b, dp[20001] = {0}, ans = 0, ck[50001] = {0};
    vector<int> road[20001];
    cin >> n >> m;
    fill(&dp[2], &dp[20001], -1e9);
    for(i=0;i<m;i++) {
        cin >> a >> b;
        road[a].push_back(b);
        road[b].push_back(a);
    }
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    while(!pq.empty()) {
        int dis = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(dp[now] > dis) continue;
        for(i=0;i<road[now].size();i++) {
            int tdis = dis - 1;
            int tnow = road[now][i];
            if(dp[tnow] < tdis) {
                dp[tnow] = tdis;
                pq.push({tdis, tnow});
            }
        }
    }
    for(i=1;i<=n;i++) {
        // cout << dp[i] << " ";
        if(dp[ans] > dp[i]) ans = i;
        ck[dp[i]*-1]++;
    }
    cout << ans << " " << dp[ans]*-1 << " " << ck[dp[ans]*-1];
    return 0;
}