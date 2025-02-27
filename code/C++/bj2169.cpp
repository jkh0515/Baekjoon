//2169 로봇 조종하기 - C++17
//메모리 : 112280KB / 시간 : 336ms
//2024년 8월 7일 01:32:03

#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001][1001];
int dp[1001][1001][3];
int side[3][2] = { {0,-1},{0,1},{1,0} };
bool visit[1001][1001];
int N, M;

int DFS(int y, int x, int dir)
{
	if (y == N - 1 && x == M - 1)
		return arr[y][x];
	if (dp[y][x][dir] != -1e9)
		return dp[y][x][dir];
	for (int i = 0; i < 3; i++) {
		int ny = y + side[i][0];
		int nx = x + side[i][1];
		if (ny >= 0 && nx >= 0 && nx < M && ny < N && visit[ny][nx] == false) {
			visit[ny][nx] = true;
			dp[y][x][dir] = max(dp[y][x][dir], arr[y][x] + DFS(ny, nx, i));
			visit[ny][nx] = false;
		}
	}
	return dp[y][x][dir];
}

int main(void) {
	cin >> N >> M;
	for(int i=0;i<N;i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];

			dp[i][j][0] = -1e9;
			dp[i][j][1] = -1e9;
			dp[i][j][2] = -1e9;
			visit[i][j] = false;
		}
	}
	visit[0][0] = true;
	cout << DFS(0, 0, 0);
}