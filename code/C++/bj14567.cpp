//14567 선수과목 (Prerequisite) - C++17
//메모리 : 4820KB / 시간 : 284ms
//2024년 3월 15일 16:46:22

#include <iostream>
#include <vector>
using namespace std;

int dp[1001];
vector<int> vt[1001];

int cal(int n) {
    if(dp[n] != -1) return dp[n];
    int a = 0, i;
    for(i=0;i<vt[n].size();i++)
        a = max(a, cal(vt[n][i]));
    return dp[n] = a + 1;
}

int main() {
    int n, m, a, b, i, j;
    fill(&dp[0], &dp[1001], -1);
    dp[1] = 1;
    cin >> n >> m;
    for(i=0;i<m;i++) {
        cin >> a >> b;
        vt[b].push_back(a);
    }
    for(i=1;i<=n;i++)
        cout << cal(i) << " ";
    return 0;
}