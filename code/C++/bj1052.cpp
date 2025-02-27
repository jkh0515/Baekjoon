//1052 물병 - C++17
//메모리 : 2020KB / 시간 : 300ms
//2024년 7월 20일 02:02:47

#include <iostream>
using namespace std;

int main() {
    int n, k, t, i;
    cin >> n >> k;
    for(i=0;;i++) {
        int cnt = 0;
        for(t=n+i;t!=0;t/=2)
            if(t % 2 == 1) cnt++;
        if(cnt <= k) break;
    }
    cout << i;
    return 0;
}