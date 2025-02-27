//1719 택배 - C++17
//메모리 : 2288KB / 시간 : 40ms
//2024년 2월 5일 01:46:34

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b, c, i, j;
    vector<ii> line[201];
    cin >> n >> m;
    while(m--) {
        cin >> a >> b >> c;
        line[a].push_back({b, c});
        line[b].push_back({a, c});
    }
    for(i=1;i<=n;i++) {
        priority_queue<iii> pq;
        vector<ii> node(n+1, {-1e9, -1});
        pq.push({{0, i}, 0});
        node[i] = {0, 0};
        while(!pq.empty()) {
            int tnode = pq.top().first.second;
            int tsum = pq.top().first.first;
            int root = pq.top().second;
            pq.pop();
            if(node[tnode].first < tsum) continue;
            for(j=0;j<line[tnode].size();j++) {
                ii tnj = line[tnode][j];
                int troot = root;
                if(node[tnj.first].first < tsum - tnj.second) {
                    if(troot == 0) troot = tnj.first;
                    pq.push({{tsum-tnj.second, tnj.first}, troot});
                    node[tnj.first] = {tsum-tnj.second, troot};
                }
            }
        }
        for(j=1;j<=n;j++) {
            if(node[j].second == 0) cout << "- ";
            else cout << node[j].second << " ";
        }
        cout << "\n";
    }
    return 0;
}