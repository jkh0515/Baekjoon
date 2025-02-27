//4153 직각삼각형 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2023년 8월 4일 00:20:53

#include <iostream>
using namespace std;

int max(int a, int b, int c) {
    if(a>=b and a>=c) return a*a;
    else if(b>=a and b>=c) return b*b;
    else return c*c;
}

int notmax(int a, int b, int c) {
    if(a>=b and a>=c) return b*b+c*c;
    else if(b>=a and b>=c) return a*a+c*c;
    else return a*a+b*b;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    while(a != 0 and b != 0 and c != 0) {
        if(max(a, b, c) == notmax(a, b, c)) {
            cout << "right" << endl;
            cin >> a >> b >> c;
        }
        else {
            cout << "wrong" << endl;
            cin >> a >> b >> c;
        }
    }
    return 0;
}