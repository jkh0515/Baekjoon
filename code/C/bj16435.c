//16435 스네이크버드 - C99
//메모리 : 1112KB / 시간 : 0ms
//2024년 1월 6일 20:41:06

#include <stdio.h>

int main() {
    int n, len, temp, arr[10001] = {0};
    scanf("%d %d", &len, &n);
    for(int i=0;i<len;i++) {
        scanf("%d", &temp);
        arr[temp]++;
    }
    for(int i=1;i<10001;i++) {
        if(i>n) break;
        for(int j=0;j<arr[i];j++)
            n++;
    }
    printf("%d", n);
    return 0;
}