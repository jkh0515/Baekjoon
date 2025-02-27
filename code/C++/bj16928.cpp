//16928 뱀과 사다리 게임 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 5월 9일 01:29:24

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int i, n, m, x, y, snake[101] = {0}, ladder[101] = {0}, dp[101] = {0};
    fill(&dp[1], &dp[101], 1e9);
    for(i=0;i<=100;i++) {
        snake[i] = i;
        ladder[i] = i;
    }
    cin >> n >> m;
    while(n--) {
        cin >> x >> y;
        ladder[x] = y;
    }
    while(m--) {
        cin >> x >> y;
        snake[x] = y;
    }
    queue<pair<int, int>> q;
    q.push({0, 1});
    while(!q.empty()) {
        int t = q.front().first;
        int n = q.front().second;
        q.pop();
        if(dp[n] < t) continue;
        for(i=1;i<=6;i++) {
            int tt = t + 1;
            int tn = n + i;
            if(tn > 100) continue;
            while(1) {
                if(tn != snake[tn]) tn = snake[tn];
                else if(tn != ladder[tn]) tn = ladder[tn];
                else break;
            }
            if(dp[tn] > tt) {
                dp[tn] = tt;
                q.push({tt, tn});
            }
        }
    }
    cout << dp[100];
    return 0;
}