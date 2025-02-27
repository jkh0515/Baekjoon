//11866 요세푸스 문제 0 - C++17
//메모리 : 2020KB / 시간 : 12ms
//2024년 3월 4일 00:27:32

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, i, a = 0, idx = -1, arr[1000] = {0};
    cin >> n >> k;
    cout << "<";
    while(a != n) {
        for(i=0;i<k;i++) {
            idx++;
            while(arr[idx%n] == 1)
                idx++;
        }
        idx %= n;
        a++;
        cout << idx+1;
        if(a != n) cout << ", ";
        arr[idx] = 1;
    }
    cout << ">";
    return 0;
}