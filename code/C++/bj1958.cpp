//1958 LCS 3 - C++17
//메모리 : 6048KB / 시간 : 8ms
//2024년 4월 30일 21:51:54

#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][101][101];

int lcs(string a, string b, string c) {
    a = '0' + a;
    b = '0' + b;
    c = '0' + c;
    for(int i=1;i<a.size();i++) {
        for(int j=1;j<b.size();j++) {
            for(int k=1;k<c.size();k++) {
                if(a[i] == b[j] and b[j] == c[k]) dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                else dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1], dp[i-1][j-1][k], dp[i-1][j][k-1], dp[i][j-1][k-1]});
            }
        }
    }
    return dp[a.size()-1][b.size()-1][c.size()-1];
}

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    cout << lcs(a, b, c);
    return 0;
}