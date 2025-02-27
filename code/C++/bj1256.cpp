//1256 사전 - C++17
//메모리 : 2060KB / 시간 : 0ms
//2024년 3월 14일 01:53:04

#include <iostream>

using namespace std;

int n, m, k, i, j;
int dp[101][101] = {0};
int main() {
	cin >> n >> m >> k;
	for (i = 1; i <= 100; i++)
		dp[i][0] = 1, dp[0][i] = 1;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			if (dp[i][j] > 1000000000) dp[i][j] = 1000000000;
		}
	}
	if (dp[n][m] < k) {
		cout << -1; return 0 ;
	}
	int a_cnt = n;
	int z_cnt = m;
	for (i = 0; i < n + m; i++) {
		int as = dp[a_cnt - 1][z_cnt];
		if (a_cnt == 0) {
			cout << 'z';
			z_cnt--;
		}
		else if (z_cnt == 0) {
			cout << 'a';
			a_cnt--;
		}
		else if (k <= as) {
			cout << 'a';
			a_cnt--;
		}
		else {
			k = k - as;
			cout << 'z';
			z_cnt--;
		}
	}

	return 0;
}