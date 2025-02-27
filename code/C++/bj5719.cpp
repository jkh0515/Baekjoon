//5719 거의 최단 경로 - C++17
//메모리 : 3048KB / 시간 : 128ms
//2024년 2월 22일 19:05:53

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m, s, d, a, b, c, i, j, pnd, nd;
    while(1) {
        j = 0;
        cin >> n >> m;
        if(n + m == 0) break;
        cin >> s >> d;
        vector<pair<int, int>> vt[501], prev[501];
        queue<int> delq;
        int node[501], pqs[501][501] = {0}, marr[501] = {0};
        fill(&node[0], &node[502], -1e9);
        fill(&marr[0], &marr[502], -1e9);
        priority_queue<pair<int, int>> pq;
        for(i=0;i<m;i++) {
            cin >> a >> b >> c;
            vt[a].push_back({c, b});
            pqs[a][b] = vt[a].size() - 1;
        }
        for(j=0;j<2;j++) {
            pq = priority_queue<pair<int, int>>();
            fill(&node[0], &node[502], -1e9);
            node[s] = 0;
            pq.push({0, s});
            while(!pq.empty()) {
                int w = pq.top().first;
                int r = pq.top().second;
                pq.pop();
                if(w < node[d] or w <= -1e9) break;
                // cout << w << " " << r << endl;
                if(node[r] < w) continue;
                for(i=0;i<vt[r].size();i++) {
                    int tw = w - vt[r][i].first;
                    int tr = vt[r][i].second;
                    if(node[tr] < tw) {
                        // cout << tr << " " << node[tr] << " " << tw << endl;
                        node[tr] = tw;
                        pq.push({tw, tr});
                        marr[tr] = max(marr[tr], tw);
                    }
                    if(j == 0 and node[tr] <= tw) {
                        prev[tr].push_back({r, node[tr]});
                        // cout << tr << " " << r << " " << node[tr] << endl;
                    }
                }
            }
            nd = node[d];
            if(nd <= -1e9) break;
            if(j == 0) {
                pnd = nd;
                delq.push(d);
                while(!delq.empty()) {
                    int dq = delq.front();
                    delq.pop();
                    for(i=0;i<prev[dq].size();i++) {
                        if(prev[dq][i].second < marr[dq] or vt[prev[dq][i].first][pqs[prev[dq][i].first][dq]].first == 1e9) continue;
                        // cout << dq << " " << prev[dq][i].first << " " << vt[prev[dq][i].first][pqs[prev[dq][i].first][dq]].first << endl;
                        vt[prev[dq][i].first][pqs[prev[dq][i].first][dq]].first = 1e9;
                        delq.push(prev[dq][i].first);
                    }
                }
            }
        }
        if(nd <= -1e9) cout << "-1\n";
        else cout << nd * -1 << endl;
    }
    return 0;
}