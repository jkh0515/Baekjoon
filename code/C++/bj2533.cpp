//2533 사회망 서비스(SNS) - C++17
//메모리 : 70648KB / 시간 : 736ms
//2024년 6월 3일 01:20:58

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> vt[1000001];
int dp[1000001][2];
bool ck[1000001];

void dfs(int node) {
    ck[node] = true;
    dp[node][0] = 0;
    dp[node][1] = 1;
    for(int i=0;i<vt[node].size();i++) {
        int t = vt[node][i];
        if(ck[t] == true) continue;
        dfs(t);
        dp[node][0] += dp[t][1];
        dp[node][1] += min(dp[t][0], dp[t][1]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, i, j, a, b;
    cin >> n;
    for(i=1;i<n;i++) {
        cin >> a >> b;
        vt[a].push_back(b);
        vt[b].push_back(a);
    }
    dfs(1);
    cout << min(dp[1][0], dp[1][1]);
    return 0;
}