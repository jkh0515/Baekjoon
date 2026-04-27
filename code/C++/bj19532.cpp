//19532 수학은 비대면강의입니다 - C++17
//메모리 : 1112KB / 시간 : 0ms
//2026년 4월 13일 13:48:49

#include <stdio.h>

int main() {
    int a, b, c, d, e, f, t;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    t = (c * d - f * a) / (b * d - e * a);
    if(a != 0) {
        printf("%d %d\n", (c - t * b) / a, t);
    }
    else {
        printf("%d %d\n", (f - t * e) / d, t);
    }
    return 0;
}