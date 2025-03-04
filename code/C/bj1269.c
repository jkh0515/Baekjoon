//1269 대칭 차집합 - C99
//메모리 : 98648KB / 시간 : 164ms
//2024년 1월 9일 14:47:35

#include <stdio.h>
#include <stdbool.h>

int main() {
    int a, b, temp;
    bool arr[100000001] = {0};
    scanf("%d %d", &a, &b);
    int answer = a + b;
    for(int i=0;i<a;i++) {
        scanf("%d", &temp);
        arr[temp] = 1;
    }
    for(int i=0;i<b;i++) {
        scanf("%d", &temp);
        if(arr[temp] == 1)
            answer -= 2;
    }
    printf("%d", answer);
    return 0;
}
