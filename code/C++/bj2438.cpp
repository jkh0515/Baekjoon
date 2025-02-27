//2438 별 찍기 - 1 - C++17
//메모리 : 2020KB / 시간 : 4ms
//2023년 6월 4일 23:42:05

#include <iostream>

using namespace std;

int main()
{
    int N, i, j;
    cin >> N;
    for(i=1;i<=N;i++) {
        for(j=0;j<i;j++) {
            cout << "*";
        }
        cout << endl;
    }
    
    return 0;
}