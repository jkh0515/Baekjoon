//1541 잃어버린 괄호 - C++17
//메모리 : 2024KB / 시간 : 0ms
//2024년 6월 20일 00:29:28

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, temp = "";
    int i, w = 1, ans = 0;
    cin >> str;
    for(i=0;i<str.size();i++) {
        if(str[i] < '0') {
            ans += stoi(temp) * w;
            temp = "";
            if(str[i] == '-') w = -1;
        } 
        else temp += str[i];
    }
    cout << ans + stoi(temp) * w;
    return 0;
}