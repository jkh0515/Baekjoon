//1041 주사위 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 7월 13일 23:44:34

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    long long i, n, ans = 0;
    vector<long long> arr(6, 0), vt(3, 0);
    cin >> n;
    for(i=0;i<6;i++) cin >> arr[i];
    if(n == 1) {
        sort(arr.begin(), arr.end());
        for(i=0;i<5;i++) ans += arr[i]; 
    }
    else {
        vt[0] = min(arr[0], arr[5]);
        vt[1] = min(arr[1], arr[4]);
        vt[2] = min(arr[2], arr[3]);
        sort(vt.begin(), vt.end());
        vt[2] += vt[1] += vt[0];
        ans += vt[0] * ((n-2) * (n-1) * 4 + (n-2) * (n-2));
        ans += vt[1] * ((n-2) * 4 + (n-1) * 4);
        ans += vt[2] * 4;
    }
    cout << ans;
    return 0;
}