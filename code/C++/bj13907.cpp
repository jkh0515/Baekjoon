//13907 세금 - C++17
//메모리 : 25300KB / 시간 : 1840ms
//2024년 5월 31일 01:04:37

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, k, rhs, lhs, a, b, c, i, j, dp[1001][1001] = {0};
    cin >> n >> m >> k;
    vector<pair<int, int>> vt[1001];
    vector<int> tax;
    cin >> rhs >> lhs;
    for(i=0;i<m;i++) {
        cin >> a >> b >> c;
        vt[a].push_back({b, c});
        vt[b].push_back({a, c});
    }
    for(i=0;i<k;i++) {
        cin >> a;
        tax.push_back(a);
    }
    priority_queue<pair<pair<int, int>, int>> pq;
    pq.push({{0, 0}, rhs});
    fill(&dp[0][0], &dp[1000][1001], -1e9);
    dp[0][0] = 0;
    while(!pq.empty()) {
        int w = pq.top().first.first;
        int t = pq.top().first.second;
        int r = pq.top().second;
        pq.pop();
        if(t >= n) continue;
        // cout << w << " " << t << " " << r << endl;
        for(i=0;i<vt[r].size();i++) {
            int tw = w - vt[r][i].second;
            int tt = t + 1;
            int tr = vt[r][i].first;
            if(dp[tr][tt] < tw) {
                dp[tr][tt] = tw;
                pq.push({{tw, tt}, tr});
            }
        }
    }
    c = 0;
    for(i=0;i<=k;i++) {
        int ans = -1e9;
        for(j=1;j<n;j++) {
            if(dp[lhs][j] <= -1e9) continue;
            // cout << dp[lhs][j] - c * j << " ";
            ans = max(ans, dp[lhs][j] - c * j);
        } 
        c += tax[i];
        // cout << endl;
        cout << ans * -1 << "\n";
    }
    return 0;
}