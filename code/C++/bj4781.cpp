//4781 사탕 가게 - C++17
//메모리 : 2060KB / 시간 : 264ms
//2024년 3월 20일 00:18:28

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int n, dp[10001], c, M, P;
double m, p;

int main() {
    while (1) {
        cin >> n >> m;
        M = (int)(m * 100.0 + 0.5);
        if(n == 0 and M == 0) break;
        fill(&dp[0], &dp[10001], 0);
        while (n--) {
            cin >> c >> p;
            P = (int)(p * 100.0 + 0.5);
            for (int idx=P;idx<=M;idx++)
                dp[idx] = max(dp[idx], dp[idx - P] + c);
        }
        cout << dp[M] << '\n';
    }
    return 0;
}