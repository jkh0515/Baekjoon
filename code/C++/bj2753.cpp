//2753 윤년 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2023년 6월 4일 22:54:16

#include <iostream>

using namespace std;

int main()
{
    int year;
    cin >> year;
    if (year % 4 == 0 && year % 100 != 0 ) cout << "1";
    else if(year % 400 == 0) cout << "1";
    else cout << "0";
    
    return 0;
}