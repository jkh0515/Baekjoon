//1149 RGB거리 - C++17
//메모리 : 1124KB / 시간 : 0ms
//2024년 6월 26일 02:46:17

#include <stdio.h>
#include <algorithm>
using namespace std;

int dp[1005][3];

int main(){
	int n, ans, i, j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<3;j++)
			scanf("%d",&dp[i][j]);
	for(i=1;i<n;i++){
		dp[i][0] += min(dp[i-1][1],dp[i-1][2]);
		dp[i][1] += min(dp[i-1][0],dp[i-1][2]);
		dp[i][2] += min(dp[i-1][0],dp[i-1][1]);
	}
	ans = min({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
	printf("%d",ans);
	return 0;
}