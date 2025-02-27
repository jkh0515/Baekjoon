//7569 토마토 - C++17
//메모리 : 13272KB / 시간 : 268ms
//2024년 5월 10일 16:56:52

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int arr[101][101][101], dp[101][101][101];
int nx[] = {1, -1, 0, 0, 0, 0}, ny[] = {0, 0, 1, -1, 0, 0}, nz[] = {0, 0, 0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, h, i, j, k, ans = 0;
    fill(&dp[0][0][0], &dp[100][100][101], -1e9);
    priority_queue<pair<int, pair<int, pair<int, int>>>> pq;
    cin >> n >> m >> h;
    for(i=0;i<h;i++) {
        for(j=0;j<m;j++) {
            for(k=0;k<n;k++) {
                cin >> arr[k][j][i];
                if(arr[k][j][i] == 1) {
                    dp[k][j][i] = 0;
                    pq.push({0, {k, {j, i}}});
                }
                if(arr[k][j][i] == -1) {
                    //cout << i << " " << j << endl;
                    dp[k][j][i] = 1e9;
                }
            }
        }
    }
    while(!pq.empty()) {
        int t = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second.first;
        int z = pq.top().second.second.second;
        pq.pop();
        if(dp[x][y][z] > t) continue;
        for(i=0;i<6;i++) {
            int tx = x + nx[i];
            int ty = y + ny[i];
            int tz = z + nz[i];
            int tt = t - 1;
            if(tx < 0 or tx >= n or ty < 0 or ty >= m or tz < 0 or tz >= h) continue;
            if(dp[tx][ty][tz] < tt) {
                dp[tx][ty][tz] = tt;
                pq.push({tt, {tx, {ty, tz}}});
            }
        }
    }
    for(i=0;i<h;i++) {
        for(j=0;j<m;j++) {
            for(k=0;k<n;k++) {
                ans = min(ans, dp[k][j][i]);
                // cout << dp[k][j][i] << " ";
            }
            // cout << endl;
        }
        // cout << endl;
    }
    if(ans == -1e9) cout << "-1";
    else cout << ans * -1;
    return 0;
}