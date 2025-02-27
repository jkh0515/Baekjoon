//3009 네 번째 점 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 6월 5일 01:12:15

#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    if(a == c) cout << e;
    else if (c == e) cout << a;
    else cout << c;
    cout << " ";
    if(b == d) cout << f;
    else if(d == f) cout << b;
    else cout << d;
    return 0;
}