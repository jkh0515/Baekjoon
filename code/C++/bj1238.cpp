//1238 파티 - C++17
//메모리 : 2288KB / 시간 : 0ms
//2024년 2월 6일 14:14:57

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ii;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, m, x, a, b, c, i, ans = 0;
    cin >> n >> m >> x;
    vector<ii> road[1001], road2[1001];
    priority_queue<ii> pq;
    vector<int> node(n+1, -1e9), node2(n+1, -1e9);
    node[x] = 0;
    pq.push({0, x});
    while(m--) {
        cin >> a >> b >> c;
        road[a].push_back({b, c});
        road2[b].push_back({a, c});
    }
    while(!pq.empty()) {
        int tnode = pq.top().second;
        int tsum = pq.top().first;
        pq.pop();
        if(node[tnode] < tsum) continue;
        for(i=0;i<road[tnode].size();i++) {
            ii tnj = road[tnode][i];
            if(node[tnj.first] < tsum-tnj.second) {
                pq.push({tsum-tnj.second, tnj.first});
                node[tnj.first] = tsum-tnj.second;
            }
        }
    }
    node2[x] = 0;
    pq.push({0, x});
    while(!pq.empty()) {
        int tnode = pq.top().second;
        int tsum = pq.top().first;
        pq.pop();
        if(node2[tnode] < tsum) continue;
        for(i=0;i<road2[tnode].size();i++) {
            ii tnj = road2[tnode][i];
            if(node2[tnj.first] < tsum-tnj.second) {
                pq.push({tsum-tnj.second, tnj.first});
                node2[tnj.first] = tsum-tnj.second;
            }
        }
    }
    for(i=1;i<=n;i++)
        ans = min(ans, node[i]+node2[i]);
    cout << ans*-1;
    return 0;
}
