//11659 구간 합 구하기 4 - C++17
//메모리 : 2684KB / 시간 : 52ms
//2026년 3월 25일 15:21:58

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    long int sum[100001] = {0};
    int n, m, i, j, k;
    scanf("%d %d", &n, &m);
    scanf("%d", &sum[1]);
    for(i=2;i<=n;i++) {
        scanf("%d", &j);
        sum[i] = sum[i-1] + j;
    }
    for(i=0;i<m;i++) {
        scanf("%d %d", &j, &k);
        printf("%d\n", sum[k] - sum[j-1]);
    }
    return 0;
}