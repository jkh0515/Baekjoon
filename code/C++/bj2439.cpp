//2439 별 찍기 - 2 - C++17
//메모리 : 2020KB / 시간 : 4ms
//2023년 6월 6일 16:16:05

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<n-i;j++) {
            cout << " ";
        }
        for(int j=0;j<i;j++) {
            cout << "*";
        }   
        cout << endl;
    }
    
    return 0;
}