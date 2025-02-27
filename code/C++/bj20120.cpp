//20120 호반우와 리듬게임 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 4월 3일 22:47:22

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, t, i, j;
    long long a = 0, b = 0, c, dp[1001] = {0};
    cin >> n >> dp[1];
    dp[0] = 0;
    for(i=1;i<n;i++) {
        cin >> t;
        c = -1e18;
        // dp[i+1] = dp[i] + (i+1) * t;
        for(j=i;j>=1;j--) {
            c = max(c, dp[j]);
            dp[j+1] = dp[j] + t * (j+1);
            // cout << dp[j] << " ";
        }
        // cout << "   " << a << " " << b << endl;
        dp[0] = max(a, b);
        dp[1] = dp[0] + t;
        b = a;
        a = c;
        // cout << a << " " << b << " " << c << endl;
    }
    c = max(a, b);
    for(i=1;i<=n;i++)
        c = max(c, dp[i]);
    if(c < 0) cout << "0";
    else cout << c;
    return 0;
}