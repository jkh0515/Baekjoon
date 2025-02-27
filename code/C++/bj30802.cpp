//30802 웰컴 키트 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 6월 8일 21:34:02

#include <iostream>
using namespace std;

int main() {
    int i, n, arr[6], a, b, ans = 0;
    cin >> n;
    for(i = 0; i < 6; i++)
        cin >> arr[i];
    cin >> a >> b;
    for(i = 0; i < 6; i++) {
        ans += arr[i] / a;
        if(arr[i] % a != 0) ans++;
    }
    cout << ans << "\n";
    cout << n / b << " " << n % b;
    return 0;
}