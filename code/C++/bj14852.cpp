//14852 타일 채우기 3 - C++17
//메모리 : 17644KB / 시간 : 12ms
//2024년 3월 28일 02:05:52

#include <iostream>
using namespace std;

long long int n, dp[1000001][2];

int main() {
    dp[0][0] = 0;
    dp[1][0] = 2;
    dp[2][0] = 7;
    dp[2][1] = 1;
    cin >> n;
    for(int i=3;i<=n;i++){
        dp[i][1] = (dp[i-3][0] +dp[i-1][1])%1000000007;
        dp[i][0] = (3*dp[i-2][0]+2*dp[i-1][0]+2*dp[i][1])%1000000007;
    }
    cout << dp[n][0];
}