//2193 이친수 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 1월 20일 15:04:22

#include <iostream>

int main() {
    int n, i;
    long arr[90] = {1, 1, };
    scanf("%d", &n);
    for(i=2;i<n;i++)
        arr[i] = (arr[i-1] + arr[i-2]);
    printf("%ld", arr[n-1]);
    return 0;
}