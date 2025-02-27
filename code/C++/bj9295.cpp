//9295 주사위 - C++17
//메모리 : 2020KB / 시간 : 24ms
//2024년 8월 15일 00:45:04

#include <iostream>
using namespace std;

int main() {
    int n, a, b;
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> a >> b;
        cout << "Case " << i << ": " << a + b << "\n";
    }
    return 0;
}