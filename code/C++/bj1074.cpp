//1074 Z - C++17
//메모리 : 2208KB / 시간 : 0ms
//2024년 5월 9일 00:24:56

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    int i, j, n, x, y, ans = 0, dx[15] = {2, }, dy[15] = {1, };
    for(i=1;i<15;i++) {
        dx[i] = dx[i-1] * 4;
        dy[i] = dy[i-1] * 4;
    }
    cin >> n >> x >> y;
    for(i=pow(2, n),j=n;j>=0;i/=2,j--) {
        if(x >= i) {
            ans += dx[j];
            x -= i;
        }
        if(y >= i) {
            ans += dy[j];
            y -= i;
        }
    }
    cout << ans;
    return 0;
}