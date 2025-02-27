//2744 대소문자 바꾸기 - C++17
//메모리 : 2024KB / 시간 : 0ms
//2023년 6월 5일 23:29:19

#include <iostream>

using namespace std;

int main() {
    string a;
    cin >> a;
    for(int i=0;i<a.length();i++) {
        if(int(a[i]) >= 65 && int(a[i]) <= 90) a[i] = tolower(a[i]);
        else a[i] = toupper(a[i]);
        cout << a[i];
    }
    
}