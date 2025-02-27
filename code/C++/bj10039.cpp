//10039 평균 점수 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 6월 10일 21:10:14

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int i, t, sum = 0;
    for(i=0;i<5;i++) {
        cin >> t;
        sum += max(40, t);
    }
    cout << sum / 5;
    return 0;
}