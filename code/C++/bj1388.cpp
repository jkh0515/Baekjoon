//1388 바닥 장식 - C++17
//메모리 : 2040KB / 시간 : 0ms
//2024년 1월 27일 21:10:48

#include <iostream>

#include <vector>

using namespace std;

int arr[51][51], ck[51][51];

int cal(int x, int y, int t) {

    if(ck[x][y] != -1) return -1;

    if(arr[x][y] != t) return 0;

    ck[x][y] = 1;

    if(t == 0) cal(x, y+1, t);

    else cal(x+1, y, t);

    return 0;

}

int main() {

    cin.tie(0);

    cout.tie(0);

    int n, m, i, j, answer = 0;

    char ch;

    cin >> n >> m;

    for(i=0;i<n;i++) {

        for(j=0;j<m;j++) {

            cin >> ch;

            if(ch == '-') arr[i][j] = 0;

            else arr[i][j] = 1;

            ck[i][j]  = -1;

        }

    }

    for(i=0;i<n;i++) {

        for(j=0;j<m;j++) {

            if(cal(i, j, arr[i][j]) == 0) answer++;

        }

    }

    cout << answer;

    return 0;

}