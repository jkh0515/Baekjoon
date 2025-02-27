//12738 가장 긴 증가하는 부분 수열 3 - C++17
//메모리 : 9832KB / 시간 : 184ms
//2024년 3월 31일 11:52:34

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, i, j, top = 1, dp[1000002], arr[1000001];


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    fill(&dp[0], &dp[1000002], 1e9);
    for(i=1;i<=n;i++)
        cin >> arr[i];
    dp[1] = arr[1];
    for(i=2;i<=n;i++) {
        j = lower_bound(dp+1, dp+top+1, arr[i]) - dp;
        dp[j] = min(dp[j], arr[i]);
        top = max(top, j);
        // for(int k=1;k<=n;k++)
        //     cout << dp[k] << " ";
        // cout << endl;
    }
    cout << top;
    return 0;
}