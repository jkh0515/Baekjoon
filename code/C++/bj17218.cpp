//17218 비밀번호 만들기 - C++17
//메모리 : 2024KB / 시간 : 0ms
//2024년 4월 27일 00:02:29

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    vector<int> ch[26], vt[40], ans;
    string a, b;
    int i, j, k, len = 0, top = 0, dp[40], prev[40][26];
    cin >> a >> b;
    fill(&dp[0], &dp[40], 40);
    for(i=0;i<a.size();i++)
        ch[a[i]-'A'].push_back(i);
    for(i=0;i<b.size();i++) {
        if(ch[b[i]-'A'].empty()) continue;
        for(j=0;j<ch[b[i]-'A'].size();j++)
            vt[len].push_back(ch[b[i]-'A'][j]);
        len++;
    }
    dp[0] = vt[0][0];
    for(i=1;i<len;i++) {
        for(j=vt[i].size()-1;j>=0;j--) {
            k = lower_bound(dp, dp+top+1, vt[i][j]) - dp;
            top = max(top, k);
            if(dp[k] > vt[i][j]) {
                dp[k] = vt[i][j];
                prev[k][vt[i][j]] = dp[max(0, k-1)];
            }
        }
    }
    // cout << top << " " << dp[top];
    ans.push_back(dp[top]);
    j = dp[top];
    for(i=top;i>0;i--) {
        ans.push_back(prev[i][j]);
        j = prev[i][j];
    }
    for(i=ans.size()-1;i>=0;i--)
        cout << a[ans[i]];
    return 0;
}