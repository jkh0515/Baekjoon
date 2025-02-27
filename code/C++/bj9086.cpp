//9086 문자열 - C++17
//메모리 : 2024KB / 시간 : 0ms
//2023년 6월 5일 23:46:17

#include <iostream>

using namespace std;

int main() {
    int T;
    string str;
    cin >> T;
    for(int i=0;i<T;i++) {
        cin >> str;
        cout << str.front() << str.back() << endl;
    }
    
    return 0;
}