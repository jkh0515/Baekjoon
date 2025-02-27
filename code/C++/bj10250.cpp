//10250 ACM 호텔 - C++17
//메모리 : 2020KB / 시간 : 4ms
//2023년 6월 7일 23:53:08

#include <iostream>

using namespace std;

int main()
{
    int T, H , W = 0, N = 0, A, B;
    cin >> T;
    for(int i=0;i<T;i++) {
        cin >> H >> W >> N;
        A = N % H;
        B = N / H;
        if(A == 0) A = H;
        else B++;
        // if(B == 0) B = 1;
        cout << A * 100 + B << endl;
    }

    return 0;
}