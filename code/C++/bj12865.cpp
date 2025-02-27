//12865 평범한 배낭 - C++17
//메모리 : 41476KB / 시간 : 28ms
//2024년 7월 26일 00:28:54

#include <iostream>
#include <algorithm>
using namespace std;
int n, k, i, j, w, v, arr[100][2] = {0}, dp[101][100001] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(i=1;i<=n;i++)
        cin >> arr[i][0] >> arr[i][1];
    for(i=1;i<=n;i++) {
        for(j=0;j<arr[i][0];j++)
            dp[i][j] = dp[i-1][j];
        for(j=arr[i][0];j<=k;j++)
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-arr[i][0]] + arr[i][1]);
    }
    cout << dp[n][k];
    return 0;
}