//14226 이모티콘 - C++17
//메모리 : 33300KB / 시간 : 20ms
//2024년 3월 18일 21:49:00

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

long long s, dp[2001][2001];

int main() {
    cin >> s;
    fill(&dp[1][1], &dp[2000][2001], 1e18);
    queue<pair<pair<int, int>, int>> q;
    q.push({{1, 0}, 0});
    while(!q.empty()) {
        int n = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();
        // cout << n << " " << c << " " << t << endl;
        if(dp[n][c] > t) continue;
        if(n == s) {
            cout << t;
            break;
        }
        if(n >= 1 and n <= 2000 and dp[n][n] > t+1) {
            q.push({{n, n}, t+1});
            dp[n][n] = t+1;
        }
        if(c > 0 and n+c <= 2000 and dp[n+c][c] > t+1) {
            q.push({{n+c, c}, t+1});
            dp[n+c][c] = t+1;
        }
        if(n >= 1 and n <= 2000 and dp[n-1][c] > t+1) {
            q.push({{n-1, c}, t+1});
            dp[n-1][c] = t+1;
        }
    }
    return 0;
}