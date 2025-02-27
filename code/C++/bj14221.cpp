//14221 편의점 - C++17
//메모리 : 5164KB / 시간 : 152ms
//2024년 2월 20일 01:35:14

#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, pair<int, int>> iii;

int main() {
    int n, m, a, b, c, p, q, i, j, an, ad = 1e9;
    cin >> n >> m;
    vector<pair<int, int>> vt[5001];
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    int node[5001];
    fill(&node[0], &node[n+1], 1e9);
    // fill(&arr[0], &arr[n+1], 1e9);
    for(i=0;i<m;i++) {
        cin >> a >> b >> c;
        vt[a].push_back({c, b});
        vt[b].push_back({c, a});
    }
    cin >> p >> q;
    for(i=0;i<p;i++) {
        cin >> a;
        pq.push({0, {a, a}});
        node[a] = 0;
    }
    for(i=0;i<q;i++) {
        cin >> a;
        node[a] = -1e9;
    }
    while(!pq.empty()) {
        int w = pq.top().first;
        int r = pq.top().second.first;
        int h = pq.top().second.second;
        pq.pop();
        if(node[h] > w) continue;
        for(j=0;j<vt[h].size();j++) {
            int tw = w + vt[h][j].first;
            int th = vt[h][j].second;
            // cout << tw << " " << r << " " << th << endl;
            if(node[th] == -1e9 and ad > tw) {
                ad = tw;
                an = r;
            }
            if(node[th] > tw) {
                node[th] = tw;
                pq.push({tw, {r, th}});
            }
        }
    }
    cout << an;
    return 0;
}