//11727 2×n 타일링 2 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 5월 7일 23:13:02

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int fin, i, dp[1001];
    dp[1] = 1, dp[2] = 3;
    cin >> fin;
    for(i=3;i<=fin;i++)
        dp[i] = (dp[i-2]*2 + dp[i-1]) % 10007;
    cout << dp[fin];
    return 0;
}