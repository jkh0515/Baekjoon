//5596 시험 점수 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 6월 22일 00:28:02

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a = 0, b = 0, t, i;
    for(i=0;i<4;i++) {
        cin >> t;
        a += t;
    }
    for(i=0;i<4;i++) {
        cin >> t;
        b += t;
    }
    cout << max(a, b);
    return 0;
}