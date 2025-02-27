//15552 빠른 A+B - C++17
//메모리 : 2020KB / 시간 : 216ms
//2023년 6월 4일 23:58:38

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T, A, B;
    cin >> T;
    for(int i=0;i<T;i++) {
        cin >> A >> B;
        cout << A + B << "\n";
    }
    
    return 0;
}