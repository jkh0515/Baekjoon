//1439 뒤집기 - C++17
//메모리 : 2024KB / 시간 : 0ms
//2024년 8월 10일 02:10:41

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string str;
    cin >> str;
    int i, ans = 0, a = str[0], b = 0;
    for(i=1;i<str.size();i++) {
        if(str[i] != a) {
            if(b % 2 == 0) ans++;
            a = str[i];
            b++;
        }
    }
    cout << ans;
    return 0;
}