//11560 다항식 게임 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 3월 23일 02:49:48

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    long long n, a, b, t = 1, arr[21][211] = {0};
    arr[0][0] = 1;
    for(int i=0;i<20;i++) {
        t += i;
        for(int j=0;j<=t;j++)
            for(int k=0;k<=i+1;k++)
                arr[i+1][j+k] += arr[i][j];
    }
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a >> b;
        cout << arr[a][b] << endl;
    }
    return 0;
}