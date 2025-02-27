//11718 그대로 출력하기 - C++17
//메모리 : 2024KB / 시간 : 4ms
//2023년 6월 5일 23:44:01

#include <iostream>

using namespace std;

int main() {
    string S;
    while(getline(cin, S)) {
        if(S == "") break;
        cout << S << endl;
    }
    
    return 0;
}