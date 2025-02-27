//11985 오렌지 출하 - C++17
//메모리 : 2212KB / 시간 : 56ms
//2024년 3월 22일 00:34:13

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    long long n, m, k, i, j, dp[20001], arr[20001];
    cin >> n >> m >> k;
    for(i=1;i<=n;i++) {
        cin >> arr[i];
        dp[i] = k * i;
    }
    for(i=0;i<n;i++) {
        long long mino = arr[i+1], maxo = arr[i+1];
        for(j=1;j<=m and i+j<=n;j++) {
            mino = min(mino, arr[i+j]);
            maxo = max(maxo, arr[i+j]);
            dp[i+j] = min(dp[i+j], dp[i] + k + j * (maxo - mino));
        }
    }
    cout << dp[n];
    return 0;
}