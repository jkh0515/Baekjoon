//2178 미로 탐색 - C++17
//메모리 : 2156KB / 시간 : 0ms
//2024년 6월 28일 00:36:52

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int i, j, n, m, dp[100][100] = {0}, arr[100][100] = {0};
    int nx[] = {1, -1, 0, 0}, ny[] = {0, 0, 1, -1};
    string str;
    cin >> n >> m;
    for(i=0;i<n;i++) {
        cin >> str;
        for(j=0;j<m;j++)
            arr[i][j] = str[j] - '0';
    }
    queue<pair<int, pair<int, int>>> q;
    q.push({1, {0, 0}});
    dp[0][0] = 1;
    while(!q.empty()) {
        int w = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        for(i=0;i<4;i++) {
            int tx = x + nx[i];
            int ty = y + ny[i];
            if(tx < 0 or tx >= n or ty < 0 or ty >= m) continue;
        // cout << w << " " << tx << " " << ty << " " << dp[tx][ty] << endl;
            if(dp[tx][ty] == 0 and arr[tx][ty] == 1) {
                dp[tx][ty] = w + 1;
                q.push({w+1, {tx, ty}});
            }
        }
    }
    cout << dp[n-1][m-1];
    return 0;
}