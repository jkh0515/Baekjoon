//2739 구구단 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2023년 6월 4일 23:39:36

#include <iostream>

using namespace std;

int main()
{
    int N, i;
    cin >> N;
    for(i=1;i<10;i++) {
        cout << N << " * " << i << " = " << N*i << endl;
    }
    
    return 0;
}