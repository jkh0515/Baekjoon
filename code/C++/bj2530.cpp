//2530 인공지능 시계 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 7월 16일 23:33:02

#include <iostream>
using namespace std;

int main(){
    int h, m, s, d;
    cin >> h >> m >> s >> d;
    cout<< (h+(m+(s+d)/60)/60)%24 << " " << (m+(s+d)/60)%60 << " " << (s+d)%60;
    return 0;
}