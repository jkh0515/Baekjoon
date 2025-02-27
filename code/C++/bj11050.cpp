//11050 이항 계수 1 - C++17
//메모리 : 2348KB / 시간 : 0ms
//2024년 5월 3일 02:17:20

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << tgamma(a+1)/(tgamma(b+1)*tgamma(a-b+1));
    return 0;
}
