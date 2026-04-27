//14626 ISBN - C++17
//메모리 : 2024KB / 시간 : 0ms
//2026년 3월 25일 14:34:40

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
    bool starWeight;
    int star, sum = 0;
    string isbn;
    cin >> isbn;
    for(int i = 0;i<13;i++) {
        if(isbn[i] == '*') {
            starWeight = i % 2 == 1;
        }
        else {
            sum += (isbn[i] - '0') * (i % 2 == 0 ? 1 : 3);
        }
    }
    sum %= 10;
    star = 10 - sum;
    if(sum == 0) {
        cout << 0;
        return 0;
    }
    for(; starWeight && star % 3 != 0; star += 10);
    cout << star / (starWeight ? 3 : 1);
    return 0;
}