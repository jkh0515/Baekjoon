//2206 벽 부수고 이동하기 - C++17
//메모리 : 16144KB / 시간 : 76ms
//2024년 5월 14일 22:40:34

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1001][1001], dp[1001][1001][2];
int nx[] = {1, -1, 0, 0}, ny[] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int i, j, n, m, ans = -1;
    string str;
    cin >> n >> m;
    for(i=0;i<n;i++) {
        cin >> str;
        for(j=0;j<m;j++) {
            arr[i][j] = str[j]-'0';
            dp[i][j][0] = -1e9;
            dp[i][j][1] = -1e9;
        }
    }
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{0, 1}, {0, 0}});
    dp[0][0][1] = 0, dp[0][0][0] = 0;
    while(!q.empty()) {
        int d = q.front().first.first;
        int p = q.front().first.second;
        int x = q.front().second.first;
        int y = q.front().second.second;
        // cout << d << " " << p << " " << x << " " << y << endl;
        q.pop();
        if(x == n - 1 and y == m - 1) {
            ans = d * -1 + 1;
            break;
        }
        if(dp[x][y][p] > d) continue;
        for(i=0;i<4;i++) {
            int tx = x + nx[i];
            int ty = y + ny[i];
            int td = d - 1;
            if(tx < 0 or tx >= n or ty < 0 or ty >= m) continue;
            if(arr[tx][ty] == 1 and p == 1) {
                if(dp[tx][ty][0] < td) {
                    dp[tx][ty][0] = td;
                    q.push({{td, 0}, {tx, ty}});
                }
            }
            else if(arr[tx][ty] == 0) {
                if(dp[tx][ty][p] < td) {
                    dp[tx][ty][p] = td;
                    q.push({{td, p}, {tx, ty}});
                }
            }
        }
    }
    cout << ans;
    return 0;
}