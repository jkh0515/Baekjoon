//9694 무엇을 아느냐가 아니라 누구를 아느냐가 문제다 - C++17
//메모리 : 2024KB / 시간 : 96ms
//2024년 2월 18일 00:49:55

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int t, n, m, i, j, a, b, c;
    cin >> t;
    for(j=1;j<=t;j++) {
        cin >> n >> m;
        vector<pair<int, int>> vt[21];
        priority_queue<pair<int, int>> pq;
        int node[21] = {0}, point[21];
        fill(&node[1], &node[21], -1e9);
        for(i=0;i<n;i++) {
            cin >> a >> b >> c;
            vt[a].push_back({b, c});
            vt[b].push_back({a, c});
        }
        pq.push({0, 0});
        while(!pq.empty()) {
            int w = pq.top().first;
            int p = pq.top().second;
            pq.pop();
            if(node[p] < w) continue;
            for(i=0;i<vt[p].size();i++) {
                int tw = w - vt[p][i].second;
                int tp = vt[p][i].first;
                if(node[tp] < tw) {
                    pq.push({tw, tp});
                    node[tp] = tw;
                    point[tp] = p;
                }
            }
        }
        if(node[m-1] != -1e9) {
            vector<int> ans(1, m-1);
            int p = point[m-1];
            while(p != 0) {
                ans.push_back(p);
                p = point[p];
            }
            cout << "Case #" << j << ": 0 ";
            while(ans.size()) {
                cout << ans.back() << " ";
                ans.pop_back();
            }
            cout << "\n";
        }
        else cout << "Case #" << j << ": -1\n";
    }
    return 0;
}