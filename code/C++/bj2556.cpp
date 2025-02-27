//2556 별 찍기 - 14 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 7월 27일 01:15:54

#include <iostream>
using namespace std;

int main() {
    int i, j, t;
    cin >> t;
    for(i=0;i<t;i++) {
        for(j=0;j<t;j++)
            cout << "*";
        cout << "\n";
    }
    return 0;
}