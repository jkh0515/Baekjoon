//2738 행렬 덧셈 - C++17
//메모리 : 2020KB / 시간 : 8ms
//2023년 6월 5일 23:21:53

#include <iostream>

using namespace std;

int main() {
    int N, M, temp;
    int a[10000] = {0};
    cin >> N >> M;
    for(int i=0;i<N*M;i++) {
        cin >> temp;
        a[i] = temp;
    }
    for(int i=0;i<N*M;i++) {
        cin >> temp;
        a[i] = a[i]+temp;
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout << a[(j)+(i)*M] << " ";
        }
        cout << endl;
    }
    
}