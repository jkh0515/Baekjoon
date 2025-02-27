//2442 별 찍기 - 5 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 8월 17일 23:38:33

#include <iostream>
using namespace std;

int main() {
    int i, j, n;
    cin >> n;
    for(i=0;i<n;i++) {
        for(j=1;j<n-i;j++) cout << " ";
        for(j=0;j<2*i+1;j++) cout << "*";
        cout << "\n";
    }
    return 0;
}