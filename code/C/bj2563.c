//2563 색종이 - C99
//메모리 : 1112KB / 시간 : 0ms
//2024년 1월 8일 20:19:46

#include <stdio.h>
#include <stdbool.h>

int main() {
    int n=0, a, b, answer = 0;
    bool arr[100][100] = {0};
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d %d", &a, &b);
        for(int j=a;j<a+10;j++) {
            for(int k=b;k<b+10;k++) {
                if(arr[j][k] == 0) {
                    arr[j][k] = 1;
                    answer++;
                }
            }
        }
    }
    printf("%d", answer);
    return 0;
}
