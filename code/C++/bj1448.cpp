//1448 삼각형 만들기 - C++17
//메모리 : 5808KB / 시간 : 236ms
//2024년 1월 13일 23:23:20

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, i, sum, arr[1000001];
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr+N);
    while(--N > 1) {
        sum = arr[N] + arr[N - 1] + arr[N - 2];
        if (sum > arr[N] * 2) break;
    }
    if(N == 1) printf("-1");
    else printf("%d", sum);
    return 0;
}