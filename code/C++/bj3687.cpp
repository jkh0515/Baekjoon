//3687 성냥개비 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 4월 7일 14:30:19

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    //1 2 3 4 5 6 7 8 9 0
    //2 5 5 4 5 6 3 7 6 6
    int n, t, i, j;
    long long dp[101], arr[] = {0, 0, 1, 7, 4, 2, 0, 8};
    fill(&dp[0], &dp[101], 1e18);
    dp[1] = 9, dp[2] = 1, dp[3] = 7, dp[4] = 4, dp[5] = 2, dp[6] = 6, dp[7] = 8;
    for(i=8;i<101;i++)
        for(j=2;j<8;j++)
            dp[i] = min(dp[i], dp[i-j] * 10 + arr[j]);
    cin >> n;
    while(n--) {
        cin >> t;
        cout << dp[t] << " ";
        if(t % 2 == 1) {
            cout << "7";
            t -= 3;
        }
        while(t > 0) {
            cout << "1";
            t -= 2;
        }
        cout << "\n";
    }
    return 0;
}