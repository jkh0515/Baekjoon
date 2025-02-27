//1504 특정한 최단 경로 - C++17
//메모리 : 5720KB / 시간 : 68ms
//2024년 2월 4일 00:16:47

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, e, a, b, c, v1, v2, i, j, answer, ans[5] = {0};
    vector<ii> line[801];
    cin >> n >> e;
    while(e--) {
        cin >> a >> b >> c;
        line[a].push_back({b, c});
        line[b].push_back({a, c});
    }
    cin >> v1 >> v2;
    ii arr[] = {{1, v1}, {1, v2}, {v1, v2}, {v1, n}, {v2, n}};
    for(i=0;i<5;i++) {
        int start = arr[i].first, end = arr[i].second;
        vector<int> node(n+1, -1e9);
        priority_queue<ii> pq;
        node[start] = 0;
        pq.push({0, start});
        while(!pq.empty()) {
            int tnode = pq.top().second;
            int tsum = pq.top().first;
            pq.pop();
            if(node[tnode] < tsum) continue;
            for(j=0;j<line[tnode].size();j++) {
                ii tnj = line[tnode][j];
                if(node[tnj.first] < node[tnode] - tnj.second) {
                    pq.push({node[tnode]-tnj.second, tnj.first});
                    node[tnj.first] = node[tnode]-tnj.second;
                }
            }
        }
        ans[i] = node[end];
    }
    answer = max(ans[0]+ans[2]+ans[4], ans[1]+ans[2]+ans[3])*-1;
    if(answer >= 1e9 or answer <= 0) cout << "-1";
    else cout << answer;
    return 0;
}