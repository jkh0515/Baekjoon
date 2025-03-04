//1966 프린터 큐 - C99
//메모리 : 1116KB / 시간 : 0ms
//2024년 1월 7일 15:29:08

#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for(int i=0;i<t;i++) {
        int n, m, arr[101] = {0}, pr[10] = {0}, idx = 0, max = 0, answer = 0;
        scanf("%d %d", &n, &m);
        for(int j=0;j<n;j++) {
            scanf("%d", &arr[j]);
            pr[arr[j]]++;
            if(max < arr[j]) max = arr[j];
        }
        // printf("%d %d %d\n", n, m, max);
        while(1) {
            if(arr[idx%n] == max) {
                answer++;
                if(idx%n == m) {
                    printf("%d\n", answer);
                    break;
                }
                // printf("no : %d %d", idx%n, max);
                pr[max]--;
                arr[idx%n] = 0;
                for(int k=9;k>0;k--) {
                    if(pr[k] > 0) {
                        max = k;
                        break;
                    }
                }
            }
            idx++;
        }
    }
    return 0;
}