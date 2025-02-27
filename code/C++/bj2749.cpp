//2749 피보나치 수 3 - C++17
//메모리 : 13740KB / 시간 : 12ms
//2024년 8월 11일 01:22:41

#include <iostream>
#include <algorithm>
using namespace std;

long long n, arr[1500000];

int main() {
    cin >> n;
    arr[1] = 1;
    for(int i = 2; i < 1500000; i++) 
        arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000;
    cout << arr[n % 1500000];
    return 0;
}