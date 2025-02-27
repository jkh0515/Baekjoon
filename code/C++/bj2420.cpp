//2420 사파리월드 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2023년 6월 4일 22:56:01

#include <iostream>

using namespace std;

int main()
{
    long int N, M;
    cin >> N >> M;
    if (N > M) cout << N - M;
    else cout << M - N;
    
    return 0;
}