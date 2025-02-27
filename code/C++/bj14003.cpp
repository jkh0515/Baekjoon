//14003 가장 긴 증가하는 부분 수열 5 - C++17
//메모리 : 76940KB / 시간 : 332ms
//2024년 4월 2일 00:45:23

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, i, j, top = 1, arr[1000001];
int dp[1000002];
vector<pair<int, int>> vt[1000002];


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    fill(&dp[1], &dp[1000002], 1e9);
    for(i=1;i<=n;i++)
        cin >> arr[i];
    for(i=0;i<=n;i++)
        vt[i].push_back({1e9, 0});
    vt[1][0] = {arr[1], 0};
    dp[1] = arr[1];
    for(i=2;i<=n;i++) {
        j = lower_bound(dp+1, dp+top+1, arr[i]) - dp;
        if(dp[j] > arr[i]) {
            dp[j] = arr[i];
            vt[j].push_back({arr[i], vt[j-1].size()-1});
        }
        top = max(top, j);
        // for(int k=1;k<=top;k++)
        //     cout << dp[k] << " ";
        // cout << endl;
    }
    cout << top << endl;
    j = vt[top].size()-1;
    for(i=top;i>=1;i--) {
        arr[i] = vt[i][j].first;
        j = vt[i][j].second;
    }
    for(i=1;i<=top;i++)
        cout << arr[i] << " ";
    return 0;
}