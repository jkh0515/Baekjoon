//2444 별 찍기 - 7 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 8월 17일 00:43:11

#include <iostream>
using namespace std;

int main() {
    int n, i, j;
    cin >> n;
    for(i=0;i<n;i++) {
        for(j=1;j<n-i;j++) cout << " ";
        for(j=0;j<1+2*i;j++) cout << "*";
        cout << "\n";
    }
    for(i=1;i<n;i++) {
        for(j=0;j<i;j++) cout << " ";
        for(j=1;j<(n-i)*2;j++) cout << "*";
        cout << "\n";
    }
    return 0;
}