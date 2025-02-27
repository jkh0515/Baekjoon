//5069 미로에 갇힌 상근 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 3월 21일 01:22:52

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int t, i, n, dp[30][30][15] = {0};
    int nx[] = {-1, -1, 0, 0, 1, 1}, ny[] = {-1, 1, -2, 2, -1, 1};
    bool ck[30][30][15] = {0};
    queue<pair<pair<int, int>, int>> q;
    q.push({{14, 14}, 0});
    dp[14][14][0] = 1;
    // ck[14][14][0] = 1;
    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int w = q.front().second;
        q.pop();
        // cout << x << " " << y << " " << w << endl;
        if(w == 14) continue;
        for(i=0;i<6;i++) {
            int tx = x + nx[i];
            int ty = y + ny[i];
            if(tx < 0 or tx > 29 or ty < 0 or ty > 29) continue;
            dp[tx][ty][w+1] += dp[x][y][w];
            if(!ck[tx][ty][w+1]) {
                ck[tx][ty][w+1] = 1;
                // dp[tx][ty][w+1] += 1;
                q.push({{tx, ty}, w+1});
            }
        }
    }
    cin >> t;
    for(i=0;i<t;i++) {
        cin >> n;
        cout << dp[14][14][n] << endl;
    }
    return 0;
}