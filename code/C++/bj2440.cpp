//2440 별 찍기 - 3 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 6월 2일 04:22:04

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        for(int i=0;i<=n;i++) cout << "*";
        cout << "\n";
    }
    return 0;
}