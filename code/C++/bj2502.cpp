//2502 떡 먹는 호랑이 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2026년 4월 1일 00:17:21

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int d, k, a, b;
    int dp[30] = {0};
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<30;i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    scanf("%d %d", &d, &k);
    for(a=1;a<k;a++) {
        int t = k - (a * dp[d-3]);
        for(b=1;b<k;b++) {
            if(b * dp[d-2] == t) {
                printf("%d\n%d", a, b);
                a = k;
            }
        }
    }
    return 0;
}