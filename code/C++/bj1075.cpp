//1075 나누기 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 6월 7일 21:12:41

#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    a /= 100;
    a *= 100;
    while(a % b != 0) {
        a++;
    }
    a %= 100;
    if(a < 10) cout << "0";
    cout << a;
    return 0;
}