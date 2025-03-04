//10872 팩토리얼 - C99
//메모리 : 1112KB / 시간 : 0ms
//2022년 10월 10일 01:08:32

#include <stdio.h>

int F(int a);

int main(void){

    int N, f = 1;

    scanf("%d", &N);
    f = F(N);
    printf("%d", f);
}

int F(int a)
{
    if (a > 1)
    {   
        return a*F(a - 1);
    }
    else
        return 1;
}