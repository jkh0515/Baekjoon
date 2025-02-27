//9251 LCS - C++17
//메모리 : 5948KB / 시간 : 4ms
//2024년 4월 30일 20:48:43

#include <iostream>
#include <algorithm>
using namespace std;

int dp[1002][1002];

int lcs(string a, string b) {
    a = '0' + a;
    b = '0' + b;
    if(a.size() > b.size()) {
        string str = b;
        b = a;
        a = str;
    }
    for(int i=1;i<a.size();i++) {
        for(int j=1;j<b.size();j++) {
            if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[a.size()-1][b.size()-1];
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << lcs(a, b);
    return 0;
}