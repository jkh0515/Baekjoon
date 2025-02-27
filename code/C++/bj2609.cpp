//2609 최대공약수와 최소공배수 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 5월 3일 02:11:38

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b;
    c = __gcd(a, b);
    cout << c << "\n" << a*b/c;
    return 0;
}
