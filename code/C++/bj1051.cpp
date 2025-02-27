//1051 숫자 정사각형 - C++17
//메모리 : 2024KB / 시간 : 0ms
//2024년 1월 15일 19:23:01

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[50][50] = {0}, answer = 1;
    int n, m, min, a, b, c, d, i, j, k;
    string str;
    scanf("%d %d", &n, &m);
    min = n;
    if(min > m) min = m;
    for(i=0;i<n;i++) {
        cin >> str;
        for(j=0;j<m;j++)
            arr[j][i] = str[j]-'0';
    }
    for(i=1;i<min;i++) {
        for(j=0;j<m-i;j++) {
            for(k=0;k<n-i;k++) {
                a = arr[j][k];
                b = arr[j][k+i];
                c = arr[j+i][k];
                d = arr[j+i][k+i];
                if(a == b and b == c and c == d)
                    answer = (i+1)*(i+1);
            }
        }
    }
    printf("%d", answer);
    return 0;
}