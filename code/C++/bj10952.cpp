//10952 A+B - 5 - C++17
//메모리 : 2020KB / 시간 : 4ms
//2023년 6월 4일 23:37:33

#include <iostream>

using namespace std;

int main()
{
    int A, B, i;
    cin >> A >> B;
    while(A != 0 && B != 0) {
        cout << A + B << endl;
        if(A == 0 && B == 0) break;
        cin >> A >> B;
    }
    
    return 0;
}