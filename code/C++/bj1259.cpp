//1259 팰린드롬수 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 5월 3일 02:25:40

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int a;
    cin >> a;
    while(a != 0) {
        string str = to_string(a);
        int mid = str.size() / 2;
        string as = str.substr(0, mid), bs = str.substr(mid, mid);
        if(str.size() % 2 != 0) bs = str.substr(mid+1, mid);
        reverse(bs.begin(), bs.end());
        // cout << as << " " << bs;
        if(as == bs) cout << "yes\n";
        else cout << "no\n";
        cin >> a;
    }
    return 0;
}
