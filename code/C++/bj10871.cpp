//10871 X보다 작은 수 - C++17
//메모리 : 2020KB / 시간 : 4ms
//2023년 6월 5일 00:08:34

#include <iostream>

using namespace std;

int main()
{
    int A[10000];
    int N, X, size = 0, temp;
    
    cin >> N >> X;
    for(int i=0;i<N;i++) {
        cin >> temp;
        if(X > temp) {
            A[size] = temp;
            size ++;
        }
    }
    
    for(int i=0;i<size;i++) {
        cout << A[i] << " ";
    }
    
    return 0;
}