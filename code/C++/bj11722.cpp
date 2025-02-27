//11722 가장 긴 감소하는 부분 수열 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 3월 25일 01:52:47

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, i, j, d, m = 0, arr[1001], dp[1001], prev[1001] = {0};
    vector<int> ans;
    fill(&dp[0], &dp[1001], 1);
    cin >> n;
    for(i=0;i<n;i++)
        cin >> arr[i];
    for(i=1;i<n;i++) {
        for(j=i;j>=0;j--) {
            if(arr[i] < arr[j]) {
                if(dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }
    }
    for(i=0;i<n;i++) {
        if(m < dp[i]) {
            m = dp[i];
            d = i;
        }
    }
    cout << m;
    // int p = prev[d];
    // ans.push_back(arr[d]);
    // cout << dp[d] << "\n";
    // for(i=1;i<dp[d];i++) {
    //     ans.push_back(arr[p]);
    //     p = prev[p];
    // }
    // for(i=ans.size()-1;i>=0;i--)
    //     cout << ans[i] << " ";
    return 0;
}