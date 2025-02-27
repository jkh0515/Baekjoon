//11779 최소비용 구하기 2 - C++17
//메모리 : 4720KB / 시간 : 28ms
//2024년 5월 12일 16:11:18

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, a, b, c, i, dp[1001], prev[1001];
    fill(&dp[0], &dp[1001], -1e9);
    cin >> n >> m;
    vector<int> ans;
    vector<pair<int, int>> vt[1001];
    while(m--) {
        cin >> a >> b >> c;
        vt[a].push_back({b, c});
    }
    cin >> a >> b;
    priority_queue<pair<int, int>> pq;
    pq.push({0, a});
    dp[a] = 0;
    while(!pq.empty()) {
        int d = pq.top().first;
        int t = pq.top().second;
        pq.pop();
        if(t == b) break;
        if(dp[t] > d) continue;
        for(i=0;i<vt[t].size();i++) {
            int td = d - vt[t][i].second;
            int tt = vt[t][i].first;
            if(dp[tt] < td) {
                dp[tt] = td;
                prev[tt] = t;
                pq.push({td, tt});
            }
        }
    }
    c = b, i = 0;
    while(1) {
        ans.push_back(c);
        i++;
        if(c == a) break;
        c = prev[c];
    }
    cout << dp[b] * -1 << "\n" << i << "\n";
    for(i=ans.size()-1;i>=0;i--)
        cout << ans[i] << " ";
    return 0;
}