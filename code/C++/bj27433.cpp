//27433 팩토리얼 2 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2026년 3월 1일 21:27:57

#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    long long n, result = 1;
    cin >> n;
    while(n != 0) {
        result *= n--;
    }
    cout << result;
    return 0;
}