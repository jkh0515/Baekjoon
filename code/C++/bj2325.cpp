//2325 개코전쟁 - C++17
//메모리 : 9108KB / 시간 : 232ms
//2024년 2월 22일 14:22:30

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, m, a, b, c, i, j, ans = 0;
    int node[1001], arr[1001] = {0};
    cin >> n >> m;
    vector<pair<int, int>> vt[1001], road;
    priority_queue<pair<int, int>> pq;
    fill(&node[0], &node[n+1], -1e9);
    for(i=1;i<=m;i++) {
        cin >> a >> b >> c;
        vt[a].push_back({c, b});
        vt[b].push_back({c, a});
    }
    pq.push({0, 1});
    node[1] = 0;
    while(!pq.empty()) {
        int t = pq.top().first;
        int r = pq.top().second;
        pq.pop();
        if(r == n) break;
        if(node[r] < t) continue;
        for(i=0;i<vt[r].size();i++) {
            int wt = t - vt[r][i].first;
            int wr = vt[r][i].second;
            if(node[wr] < wt) {
                pq.push({wt, wr});
                node[wr] = wt;
                arr[wr] = r;
            }
        }
    }
    c = node[n];
    b = n;
    while(1) {
        a = arr[b];
        if(a == 0 or b == 0) break;
        road.push_back({a, b});
        b = a;
    }
    for(i=0;i<road.size();i++) {
        for(j=0;j<vt[road[i].first].size();j++) {
            if(vt[road[i].first][j].second == road[i].second) {
                a = vt[road[i].first][j].first;
                vt[road[i].first][j].first = 1e9;
                b = j;
                break;
            }
        }
        pq = priority_queue<pair<int, int>>();
        pq.push({0, 1});
        fill(&node[0], &node[n+1], -1e9);
        node[1] = 0;
        while(!pq.empty()) {
            int t = pq.top().first;
            int r = pq.top().second;
            pq.pop();
            if(r == n) break;
            if(node[r] < t) continue;
            for(j=0;j<vt[r].size();j++) {
                int wt = t - vt[r][j].first;
                int wr = vt[r][j].second;
                if(node[wr] < wt) {
                    pq.push({wt, wr});
                    node[wr] = wt;
                }
            }
        }
        ans = min(ans, node[n]);
        vt[road[i].first][b].first = a;
    }
    cout << ans * -1;
    return 0;
}
