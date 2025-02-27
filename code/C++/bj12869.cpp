//12869 뮤탈리스크 - C++17
//메모리 : 2908KB / 시간 : 0ms
//2024년 3월 26일 21:22:34

#include <iostream>
#include <algorithm>
using namespace std;

int dp[61][61][61];
int na[6][3] = {{1, 3, 9}, {1, 9, 3}, {3, 1, 9}, {3, 9, 1}, {9, 1, 3}, {9, 3, 1}};

int cal(int a, int b, int c) {
    // if(a == 0 and b == 0 and c == 0) return 0;
    if(a < 0) return cal(0, b, c);
    if(b < 0) return cal(a, 0, c);
    if(c < 0) return cal(a, b, 0);
    // cout << a << " " << b << " " << c << endl;
    if(dp[a][b][c] != -1) return dp[a][b][c];
    dp[a][b][c] = 1e9;
    for(int i=0;i<6;i++)
        dp[a][b][c] = min(dp[a][b][c], cal(a - na[i][0], b - na[i][1], c - na[i][2]) + 1);
    return dp[a][b][c];
}

int main() {
    int n, i, arr[3] = {0};
    fill(&dp[0][0][1], &dp[60][60][61], -1);
    cin >> n;
    for(i=0;i<n;i++)
        cin >> arr[i];
    cout << cal(arr[0], arr[1], arr[2]);
    return 0;
}