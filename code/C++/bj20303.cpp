//20303 할로윈의 양아치 - C++17
//메모리 : 5100KB / 시간 : 116ms
//2024년 4월 5일 02:02:23

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k, a, b, i, j, arr[30001];
    long long dp[30001] = {0}, ans = 0;
    cin >> n >> m >> k;
    bool ch[30001] = {0};
    vector<int> vt[30001];
    vector<pair<long long, int>> llvt;
    for(i=1;i<=n;i++) {
        cin >> arr[i];
    }
    for(i=0;i<m;i++) {
        cin >> a >> b;
        vt[a].push_back(b);
        vt[b].push_back(a);
    }
    for(i=1;i<=n;i++) {
        if(ch[i] == 1) continue;
        queue<int> q;
        q.push(i);
        long long sum = 0;
        int p = 0;
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            if(ch[top] == 1) continue;
            ch[top] = 1;
            p++;
            sum += arr[top];
            for(j=0;j<vt[top].size();j++)
                q.push(vt[top][j]);
        }
        if(sum != 0) llvt.push_back({sum, p});
    }
    n = llvt.size();
    fill(&dp[1], &dp[n+1], -1);
    // for(i=0;i<llvt.size();i++)
    //     cout << llvt[i].first << " " << llvt[i].second << endl;
    for(i=0;i<n;i++) {
        for(j=k-llvt[i].second;j>=0;j--) {
            if(dp[j] == -1) continue;
            dp[j+llvt[i].second] = max(dp[j+llvt[i].second], dp[j]+llvt[i].first);
        }
        // for(int l=1;l<k;l++) {
        //     cout << dp[l] << " ";
        // }
        // cout << endl;
    }
    for(i=0;i<k;i++)
        ans = max(ans, dp[i]);
    cout << ans;
    return 0;
}