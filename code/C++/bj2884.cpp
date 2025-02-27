//2884 알람 시계 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2023년 6월 6일 16:26:53

#include <iostream>

using namespace std;

int main()
{
    int H, M;
    cin >> H >> M;
    if(M >= 45) cout << H << " " << M-45;
    else {
        if(H == 0) H = 23;
        else H--;
        cout << H << " " << M+15;
    }
    return 0;
}