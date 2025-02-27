//14681 사분면 고르기 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2023년 6월 4일 22:52:14

#include <iostream>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    if (x > 0 && y > 0) cout << "1";
    else if (x < 0 && y > 0) cout << "2";
    else if (x < 0 && y < 0) cout << "3";
    else cout << "4";
    
    return 0;
}