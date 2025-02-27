//15989 1, 2, 3 더하기 4 - C++17
//메모리 : 2056KB / 시간 : 16ms
//2024년 3월 14일 22:06:51

#include <iostream>
using namespace std;

int main() {
    int t, i, n, dp[10001][4] = {0};
    dp[0][1] = 1, dp[1][1] = 1, dp[2][1] = 1, dp[2][2] = 1;
    cin >> t;
    for(i=3;i<=10000;i++) {
        dp[i][1] = dp[i-1][1];
        dp[i][2] = dp[i-2][1] + dp[i-2][2];
        dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
    }
    while(t--) {
        cin >> n;
        cout << dp[n][1] + dp[n][2] + dp[n][3] << endl;
    }
}