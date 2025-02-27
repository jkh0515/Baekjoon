//3273 두 수의 합 - C++17
//메모리 : 2876KB / 시간 : 12ms
//2024년 1월 18일 02:42:17

#include <iostream>

int main() {
    int n, a = 1, b = 1000000, x, t, i, answer = 0;
    bool arr[1000001] = {0};
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        scanf("%d", &t);
        arr[t] = 1;
    }
    scanf("%d", &x);
    while(b - a > 0) {
        while(a < b and arr[a] == 0) a++;
        while(a < b and arr[b] == 0) b--;
        if(a + b == x) answer++;
        else if(a + b > x) a--;
        else b++;
        a++;
        b--;
    }
    printf("%d", answer);
    return 0;
}