//1103 게임 - C++17
//메모리 : 2132KB / 시간 : 0ms
//2024년 1월 27일 16:14:52

#include <iostream>
#include <vector>
using namespace std;

int arr[70][70], dp[51][51], ck[51][51];
int ax[] = {1, -1, 0, 0}, ay[] = {0, 0, 1, -1};

int cal(int x, int y) {
    if(ck[x][y] != 0) return 1e6;
    if(dp[x][y] != 0) return dp[x][y];
    dp[x][y] = 1;
    ck[x][y] = 1;
    for(int i=0;i<4;i++) {
        int xx = x + ax[i] * arr[x+10][y+10];
        int yy = y + ay[i] * arr[x+10][y+10];
        if(arr[xx+10][yy+10] == 0) continue;
        dp[x][y] = max(dp[x][y], cal(xx, yy)+1);
    }
    ck[x][y] = 0;
    return dp[x][y];
}

int main() {
    cin.tie(0);
    cout.tie(0);
    int n, m, answer;
    cin >> n >> m;
    string str;
    for(int i=10;i<n+10;i++) {
        cin >> str;
        for(int j=0;j<m;j++) {
            if(str[j] == 'H') str[j] = '0';
            arr[i][j+10] = str[j]-'0';
        }
    }
    answer = cal(0, 0);
    if(answer < 10000) cout << answer;
    else cout << "-1";
    return 0;
}
