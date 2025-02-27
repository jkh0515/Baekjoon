//1463 1로 만들기 - C++17
//메모리 : 13740KB / 시간 : 12ms
//2024년 5월 10일 00:29:30

#include <iostream>
#include <algorithm>
using namespace std;

int i, n, dp[3000001];

int main() {
    fill(&dp[0], &dp[1000001], 1e9);
    dp[1] = 0;
    for(i=1;i<1000001;i++) {
        dp[i+1] = min(dp[i+1], dp[i]+1);
        dp[i*2] = min(dp[i*2], dp[i]+1);
        dp[i*3] = min(dp[i*3], dp[i]+1);
    }
    cin >> n;
    cout << dp[n];
    return 0;
}
