//1500 최대 곱 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 7월 9일 01:24:00

#include <iostream>
using namespace std;

int main() {
    long long i, n, m, ans = 1;
    cin >> n >> m;
    for(i=0;i<n%m;i++)
        ans *= (n / m) + 1;
    for(;i<m;i++)
        ans *= n / m;
    cout << ans;
    return 0;
}