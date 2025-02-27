//1309 동물원 - C++17
//메모리 : 3072KB / 시간 : 0ms
//2024년 6월 22일 21:36:27

#include <iostream>

#include <algorithm>

using namespace std;

int main() {

    int dp[100000][3], n, i;

    dp[0][0] = dp[0][1] = dp[0][2] = 1;

    cin >> n;

    for(i=0;i<n-1;i++) {

        dp[i+1][0] = (dp[i][1] + dp[i][2]) % 9901;

        dp[i+1][1] = (dp[i][0] + dp[i][2]) % 9901;

        dp[i+1][2] = (dp[i][0] + dp[i][1] + dp[i][2]) % 9901;

    }

    cout << (dp[n-1][0] + dp[n-1][1] + dp[n-1][2]) % 9901;

    return 0;

}