//2869 달팽이는 올라가고 싶다 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 3월 4일 00:51:40

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long a, b, v;
    cin >> a >> b >> v;
    cout << fixed;
    cout.precision(0);
    cout << ceil(double(v-b)/(a-b));
    return 0;
}