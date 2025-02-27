//2441 별 찍기 - 4 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 8월 16일 01:26:11

#include <iostream>
using namespace std;

int main() {
    int i, j, n;
    cin >> n;
    for(i=0;i<n;i++) {
        for(j=0;j<i;j++) cout << " ";
        for(j=n;j>i;j--) cout << "*";
        cout << "\n";
    }
    return 0;
}