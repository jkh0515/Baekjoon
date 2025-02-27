//10166 관중석 - C++17
//메모리 : 5808KB / 시간 : 112ms
//2024년 7월 11일 01:59:32

#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    bool ck[2001][2001] = {false};
    int i, j, n, m, ans = 0;
    cin >> n >> m;
    for(i=n;i<=m;i++) {
        for(j=1;j<=i;j++) {
            int t = gcd(i, j);
            if(!ck[i/t][j/t]) {
                ck[i/t][j/t] = true;
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}