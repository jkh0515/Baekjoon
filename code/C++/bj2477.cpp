//2477 참외밭 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 7월 12일 00:25:58

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int i, n, t, pw, plus = 0, d, w, arr[5] = {0};
    cin >> n >> d >> pw;
    t = pw;
    arr[d] += pw;
    for(i=0;i<5;i++) {
        cin >> d >> w;
        arr[d] += w;
        plus += pw * w;
        pw = w;
    }
    plus += w * t;
    cout << n * (plus - 2 * arr[1] * arr[3]);
    return 0;
}