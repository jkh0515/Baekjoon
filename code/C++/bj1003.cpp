//1003 피보나치 함수 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 5월 8일 22:11:19

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int i, t, n, zero[41] = {0}, one[41] = {0};
    cin >> t;
    zero[0] = 1, one[1] = 1;
    for(i=2;i<=40;i++) {
        zero[i] = zero[i-1] + zero[i-2];
        one[i] = one[i-1] + one[i-2];
    }
    while(t--) {
        cin >> n;
        cout << zero[n] << " " << one[n] << "\n";
    }
    return 0;
}
