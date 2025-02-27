//11724 연결 요소의 개수 - C++17
//메모리 : 6512KB / 시간 : 88ms
//2024년 5월 4일 16:21:36

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, a, b, i, j, ck[1001], ans = 1;
    cin >> n >> m;
    vector<int> line[1001];
    queue<int> q;
    for(i=0;i<m;i++) {
        cin >> a >> b;
        line[a].push_back(b);
        line[b].push_back(a);
    }
    for(i=1;i<=n;i++) {
        if(ck[i] != 0) continue;
        q.push(i);
        while(!q.empty()) {
            int now = q.front();
            for(j=0;j<line[now].size();j++) {
                int next = line[now][j];
                if(ck[next] == 0) {
                    ck[next] = ans;
                    q.push(next);
                }
            }
            q.pop();
        }
        ans++;
    }
    cout << ans - 1;
    return 0;
}