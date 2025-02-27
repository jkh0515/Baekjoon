//2475 검증수 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2023년 6월 5일 23:56:40

#include <iostream>

using namespace std;

int main() {
    long int n, result(0);
    for(int i=0;i<5;i++) {
        cin >> n;
        result = result + n*n;
        // cout << result << endl;
    }
    cout << result%10;
    return 0;
}
