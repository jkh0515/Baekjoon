//2747 피보나치 수 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 8월 14일 00:34:58

#include <iostream>
#include <algorithm>
using namespace std;

long long n, arr[46];

int main() {
    cin >> n;
    arr[1] = 1;
    for(int i = 2; i < 46; i++) 
        arr[i] = (arr[i - 1] + arr[i - 2]);
    cout << arr[n];
    return 0;
}