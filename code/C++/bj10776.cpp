//10776 제국 - C++17
//메모리 : 22696KB / 시간 : 156ms
//2024년 2월 23일 20:51:04

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int node[2001][2001];

int main() {
    int k, n, m, i, j, a, b, c, d, s, e, im = 0, ans = -1e9;
    cin >> k >> n >> m;
    vector<pair<int, pair<int, int>>> vt[2001];
    priority_queue<pair<int, pair<int, int>>> pq;
    for(i=0;i<m;i++) {
        cin >> a >> b >> c >> d;
        vt[a].push_back({b, {c, d}});
        vt[b].push_back({a, {c, d}});
    }
    cin >> s >> e;
    for(i=0;i<=n;i++) {
        if(i == s) continue;
        fill(&node[i][0], &node[i][2001], -1e9);
    }
    pq.push({0, {k, s}});
    while(!pq.empty()) {
        int t = pq.top().first;
        int l = pq.top().second.first;
        int r = pq.top().second.second;
        // cout << t << " " << l << " " << r << " " << endl;
        pq.pop();
        if(node[r][l] < t) continue;
        for(i=0;i<vt[r].size();i++) {
            int tt = t - vt[r][i].second.first;
            int tl = l - vt[r][i].second.second;
            int tr = vt[r][i].first;
            if(tl <= 0) continue;
            if(node[tr][tl] < tt) {
                node[tr][tl] = tt;
                pq.push({tt, {tl, tr}});
                if(tr == e) im = max(im, tl);
            }
        }
    }
    for(i=0;i<=im;i++) {
        if(node[e][i] == -1e9) continue;
        else ans = max(ans, node[e][i]);
    }
    if(ans == -1e9) cout << "-1";
    else cout << ans * -1;
    return 0;
}