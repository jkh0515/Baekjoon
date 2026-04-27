//3054 피터팬 프레임 - C++17
//메모리 : 2024KB / 시간 : 0ms
//2026년 4월 6일 13:01:14

#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str, first, second, third, fourth;
    cin >> str;

    for(int i=1;i<=str.size();i++) {
        if(i % 3 == 0) {
            first += "..*.";
            second += ".*.*";
            third += "*.";
        }
        else {
            first += "..#.";
            second += ".#.#";
            if(i != 1 && (i+1) % 3 != 0) {
                third += "*.";
            }
            else {
                third += "#.";
            }
        }
        third += str[i-1];
        third += ".";
    }
    first += ".";
    second += ".";
    if(str.size() % 3 == 0) {
        third += "*";
    }
    else {
        third += "#";
    }
    cout << first << "\n";
    cout << second << "\n";
    cout << third << "\n";
    cout << second << "\n";
    cout << first << "\n";
    return 0;
}