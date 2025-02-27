//5532 방학 숙제 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 7월 6일 01:29:54

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int l, a, b, c, d, e;
    cin >> l >> a >> b >> c >> d;
    cout << l - max(ceil((float)a / c), ceil((float)b / d));
    return 0;
}