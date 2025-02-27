//13308 주유소 - C++17
//메모리 : 124724KB / 시간 : 584ms
//2024년 2월 24일 16:45:04

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
long long node[2501][2502];
int road[2501][2501];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long am = -1e18;
    int n, m, a, b, c, i, price[2501];
    vector<int> vt[2501];
    priority_queue<pair<long long, pair<int, int>>> pq;
    cin >> n >> m;
    for(i=1;i<=n;i++) {
        cin >> price[i];
        fill(&node[i][0], &node[i][2502], -1e18);
    }
    for(i=0;i<m;i++) {
        cin >> a >> b >> c;
        road[a][b] = c;
        road[b][a] = c;
        vt[a].push_back(b);
        vt[b].push_back(a);
    }
    pq.push({0, {2501, 1}});
    while(!pq.empty()) {
        long long l = pq.top().first;
        int p = pq.top().second.first;
        int r = pq.top().second.second;
        pq.pop();
        if(node[r][p] != -1e18) continue;
        node[r][p] = l;
        if(r == n) {
            cout << l * -1;
            break;
        }
        for(i=0;i<vt[r].size();i++) {
            int tr = vt[r][i];
            int tp = min(p, price[r]);
            long long tl = l - tp * road[r][tr];
            if(node[tr][tp] == -1e18)
                pq.push({tl, {tp, tr}});
        }
    }
    return 0;
}