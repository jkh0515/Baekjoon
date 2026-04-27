//9278 절망적인 줄 - C++17
//메모리 : 2024KB / 시간 : 84ms
//2026년 3월 31일 17:23:54

#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    while(getline(cin, str)) {
        int dp[501] = {0};
        if(str[0] == ')') {
            printf("0\n");
            continue;
        }
        dp[1] = 1;
        for(int i=1;i<str.size();i++) {
            int temp[501] = {0};
            for(int j=0;j<=i && j<=500;j++) {
                if(j > 0 && str[i] != '(') {
                    temp[j-1] = (temp[j-1] + dp[j]) % 1000000;
                }
                if(j < 500 && str[i] != ')') {
                    temp[j+1] = (temp[j+1] + dp[j]) % 1000000;
                }
            }
            memcpy(dp, temp, sizeof(dp));
        }
        printf("%d\n", dp[0]);
    }
    return 0;
}