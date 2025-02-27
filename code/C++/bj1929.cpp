//1929 소수 구하기 - C++17
//메모리 : 2020KB / 시간 : 188ms
//2024년 1월 16일 21:12:35

#include <iostream>
using namespace std;

int main() {
    int n, m, tf;
    cin >> n >> m;
    for(int i=n;i<=m;i++) {
        if(i < 2) continue;
        tf = 0;
        for(int j=2;j*j<=i;j++) {
            if(i % j == 0) {
                tf = 1;
                break;
            }
        }
        if(tf == 0) printf("%d\n", i);
    }
    return 0;
}