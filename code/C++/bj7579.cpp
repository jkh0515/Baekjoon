//7579 앱 - C++17
//메모리 : 2060KB / 시간 : 0ms
//2024년 4월 3일 00:18:27

#include <iostream>
#include <algorithm>
using namespace std;
 
int n, m, i, j, ans, dp[10001], A[101], c[101];
 
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	cin >> n >> m;
	for(i=1;i<=n;i++)
		cin >> A[i];
    for(i=1;i<=n;i++)
        cin >> c[i];
    for(i=1;i<=n;i++)
        for(j=10000;j>=c[i];j--)
        	dp[j] = max(dp[j], dp[j - c[i]] + A[i]);
    while(dp[ans] < m) ans+=1;
    cout << ans;
    return 0;
}