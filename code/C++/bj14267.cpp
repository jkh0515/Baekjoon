//14267 회사 문화 1 - C++17
//메모리 : 8572KB / 시간 : 100ms
//2024년 3월 29일 00:51:04

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> vt[100001];
int arr[100001], parr[100001], dp[100001];

int main() {
    int n, m, t, w, i;
    cin >> n >> m >> t;
    for(i=2;i<n+1;i++) {
        cin >> t;
        vt[t].push_back(i);
        parr[i] = t;
    }
    for(i=0;i<m;i++) {
        cin >> t >> w;
        arr[t] += w;
    }
    for(int j=1;j<=n;j++) {
        for(int i=0;i<vt[j].size();i++) {
            dp[vt[j][i]] = max(dp[vt[j][i]], dp[parr[vt[j][i]]] + arr[vt[j][i]]);
        }
    }
    for(int i=1;i<=n;i++)
        cout << dp[i] << " ";
    return 0;
}