//9505 엔터프라이즈호 탈출 - C++17
//메모리 : 22152KB / 시간 : 3720ms
//2024년 2월 12일 20:32:02

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int arr[1001][1001], node[1001][1001];

int main() {
    int t;
    cin >> t;
    while(t--) {
        int k, h, w, b, i, j, sx, sy, ans = -1e9;
        int c[25], nx[] = {1, -1, 0, 0}, ny[] = {0, 0, 1, -1};
        string str;
        char a;
        priority_queue<pair<int, pair<int, int>>> pq;
        cin >> k >> h >> w;
        while(k--) {
            cin >> a >> b;
            c[a-65] = b;
        }
        for(i=0;i<w;i++) {
            cin >> str;
            for(j=0;j<h;j++) {
                if(str[j] == 'E') {
                    arr[i][j] = 0;
                    sx = i;
                    sy = j;
                }
                else arr[i][j] = c[str[j]-65];
                node[i][j] = -1e9;
            }
        }
        node[sx][sy] = 0;
        pq.push({0, {sx, sy}});
        while(!pq.empty()) {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int l = pq.top().first;
            pq.pop();
            // if(x < 0 or x >= w or y < 0 or y >= h) {
            //     ans = min(ans, l);
            //     continue;
            // }
            if(node[x][y] < l) continue;
            for(i=0;i<4;i++) {
                int tx = x + nx[i];
                int ty = y + ny[i];
                int tl = l - arr[tx][ty];
                if(tx < 0 or tx >= w or ty < 0 or ty >= h)
                    ans = max(ans, l);
                else if(node[tx][ty] < tl) {
                    node[tx][ty] = tl;
                    pq.push({tl, {tx, ty}});
                }
            }
        }
        cout << ans * -1 << "\n";
        // for(i=0;i<h;i++) {
        //     for(j=0;j<w;j++) {
        //         cout << node[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
    return 0;
}