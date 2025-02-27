//7576 토마토 - C++17
//메모리 : 19192KB / 시간 : 200ms
//2024년 5월 10일 15:35:46

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int arr[1001][1001], dp[1001][1001], nx[] = {1, -1, 0, 0}, ny[] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, i, j, ans = 0;
    fill(&dp[0][0], &dp[1000][1001], -1e9);
    priority_queue<pair<int, pair<int, int>>> pq;
    cin >> n >> m;
    for(i=0;i<m;i++) {
        for(j=0;j<n;j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) {
                dp[i][j] = 0;
                pq.push({0, {i, j}});
            }
            if(arr[i][j] == -1) {
                //cout << i << " " << j << endl;
                dp[i][j] = 1e9;
            }
        }
    }
    while(!pq.empty()) {
        int t = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        if(dp[x][y] > t) continue;
        for(i=0;i<4;i++) {
            int tx = x + nx[i];
            int ty = y + ny[i];
            int tt = t - 1;
            if(tx < 0 or tx >= m or ty < 0 or ty >= n) continue;
            if(dp[tx][ty] < tt) {
                dp[tx][ty] = tt;
                pq.push({tt, {tx, ty}});
            }
        }
    }
    for(i=0;i<m;i++) {
        for(j=0;j<n;j++)
            ans = min(ans, dp[i][j]);
            //cout << dp[i][j] << " ";
        //cout << endl;
    }
    if(ans == -1e9) cout << "-1";
    else cout << ans * -1;
    return 0;
}