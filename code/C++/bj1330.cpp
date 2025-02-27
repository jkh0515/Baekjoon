//1330 두 수 비교하기 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2023년 6월 4일 22:47:54

#include <iostream>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    if (A < B) cout << "<";
    else if (A > B) cout << ">";
    else cout << "==";
    
    return 0;
}