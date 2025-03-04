//10610 30 - C99
//메모리 : 1112KB / 시간 : 8ms
//2022년 10월 12일 00:55:09

#include <stdio.h>
#include <string.h>

int main(void) 
{
    char N[100001];
    scanf("%s", N);
   int i, j, len = 0, shift = 0, sum = 0, TF = 0, counting[10] = {0};
      
   len = strlen(N);
   
   for (i = 0; i < len; i++)
   {
      sum += N[i];
      counting[(int)N[i]-48] += 1;
   }
   
   if (counting[0] != 0 && sum % 3 == 0)
   {  
    for(int i=9;i>-1;i--)
    {
       if(counting[i] != 0)
       {
         for(int j=0;j<counting[i];j++)
         {
            printf("%d",i);
         }
       }
    }
   }
    else
      printf("-1");
   
    return 0;
}