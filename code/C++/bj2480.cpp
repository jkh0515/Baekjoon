//2480 주사위 세개 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 6월 13일 01:06:58

#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int arr[7] = {0}, t, a = 0;
    for(int i=0;i<3;i++) {
        cin >> t;
        arr[t]++;
    }
    for(int i=6;i>=1;i--) {
        if(arr[i] == 3) {
            a = max(a, 10000 + 1000 * i);
            break;
        }
        else if(arr[i] == 2) {
            a = max(a, 1000 + 100 * i);
            break;
        }
        else if(arr[i] == 1) a = max(a, 100 * i);
    }
    cout << a;
    return 0;
}