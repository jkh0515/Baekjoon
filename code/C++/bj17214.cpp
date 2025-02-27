//17214 다항 함수의 적분 - C++17
//메모리 : 2024KB / 시간 : 0ms
//2024년 3월 6일 23:31:22

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, a = "0", b = "";
    int i, c = 0;
    cin >> str;
    for(i=0;i<str.size();i++) {
        if(str[i] == 'x') {
            c = 1, a = b, b = "0";
            if(i != str.size()-1)
                b = str[++i];
            continue;
        }
        b += str[i];
    }
    // cout << a << " " << b;
    if(a != "0") {
        if(a == "-2") cout << "-xx";
        else if(a == "2") cout << "xx";
        else cout << stoi(a)/2 << "xx";
    }
    if(b != "0" and b != "+0" and b != "-0") {
        if(a == "0") {
            if(b == "-1") cout << "-x";
            else if(b == "+1" or b == "1") cout << "x"; 
            else cout << b << "x";
        }
        else {
            if(b == "-1") cout << "-x";
            else if(b == "+1" or b == "1") cout << "+x"; 
            else cout << b << "x";
        }
    }
    if(a == "0" and b == "0") cout << "W";
    else cout << "+W";
    return 0;
}