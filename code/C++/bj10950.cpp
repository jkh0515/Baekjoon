//10950 A+B - 3 - C++17
//메모리 : 2020KB / 시간 : 4ms
//2023년 6월 4일 23:35:27

#include <iostream>

using namespace std;

int main()
{
    int T, A, B, i;
    cin >> T;
    for(i=0;i<T;i++) {
        cin >> A >> B;
        cout << A + B << endl;
    }
    
    return 0;
}