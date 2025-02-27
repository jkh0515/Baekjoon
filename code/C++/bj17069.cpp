//17069 파이프 옮기기 2 - C++17
//메모리 : 2044KB / 시간 : 0ms
//2024년 3월 10일 21:43:01

#include <iostream>
using namespace std;
bool arr[32][32];
long long dp[3][32][32], n, ans;

long long cal(int t, int x, int y) {
    if(dp[t][x][y] != -1) return dp[t][x][y];
    if(t == 0) {
        if(y == 0) return 0;
        if(arr[x][y] or arr[x][y-1]) return 0;
        dp[0][x][y] = cal(0, x, y-1) + cal(2, x, y-1);
        return dp[0][x][y];
    }
    else if(t == 1) {
        if(x == 0) return 0;
        if(arr[x][y] or arr[x-1][y]) return 0;
        dp[1][x][y] = cal(1, x-1, y) + cal(2, x-1, y);
        return dp[1][x][y];
    }
    else {
        if(x == 0 or y == 0) return 0;
        if(arr[x][y] or arr[x][y-1] or arr[x-1][y] or arr[x-1][y-1]) return 0;
        dp[2][x][y] = cal(0, x-1, y-1) + cal(1, x-1, y-1) + cal(2, x-1, y-1);
        return dp[2][x][y];
    }
}

int main() {
    fill(&dp[0][0][0], &dp[2][31][32], -1);
    cin >> n;
    dp[0][0][1] = 1;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> arr[i][j];
    for(int i=0;i<3;i++)
        ans += cal(i, n-1, n-1);
    cout << ans;
    return 0;
}