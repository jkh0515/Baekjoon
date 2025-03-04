//1110 더하기 사이클 - C99
//메모리 : 1112KB / 시간 : 0ms
//2022년 9월 7일 17:14:07

#include <stdio.h>

int main() {
    int N;
    int n;
    int sum = 100;
    int idx = 0;
    scanf("%d",&N);

    n = N;

    while (sum != n)
    {
        sum = 0;
        sum += (N % 10) * 10;
        sum += (N / 10 + N % 10) % 10;
        N = sum;
        idx ++;
    }
    printf("%d",idx);
    return 0;
}