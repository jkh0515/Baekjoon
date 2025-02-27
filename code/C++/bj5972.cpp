//5972 택배 배송 - C++17
//메모리 : 5292KB / 시간 : 68ms
//2024년 2월 12일 00:07:45

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m, a, b, c, i;
    cin >> n >> m;
    vector<int> node(n+1, -1e9);
    vector<pair<int, int>> line[50001];
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    node[1] = 0;
    while(m--) {
        cin >> a >> b >> c;
        line[a].push_back({b, c});
        line[b].push_back({a, c});
    }
    while(!pq.empty()) {
        int cow = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(now == n) break;
        if(node[now] < cow) continue;
        for(i=0;i<line[now].size();i++) {
            int ncow = cow - line[now][i].second;
            int next = line[now][i].first;
            if(node[next] < ncow) {
                node[next] = ncow;
                pq.push({ncow, next});
            }
        }
    }
    cout << node[n] * -1;
    return 0;
}