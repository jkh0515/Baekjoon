//17144 미세먼지 안녕! - C++17
//메모리 : 2020KB / 시간 : 36ms
//2024년 5월 16일 00:11:23

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int r, c, t, a, w, i, j, k, ans = 0, arr[50][50];
    int nx[] = {0, -1, 0, 1}, ny[] = {1, 0, -1, 0};
    cin >> r >> c >> t; 
    for(i=0;i<r;i++) {
        for(j=0;j<c;j++) {
            cin >> a;
            arr[i][j] = a;
            if(a == -1) w = i;
        }
    }
    while(t--) {
        int darr[50][50] = {0};
        for(i=0;i<r;i++) {
            for(j=0;j<c;j++) {
                int d = arr[i][j] / 5;
                if(d < 1) continue;
                for(k=0;k<4;k++) {
                    int tx = i + nx[k];
                    int ty = j + ny[k];
                    if(tx < 0 or tx >= r or ty < 0 or ty >= c or arr[tx][ty] == -1) continue;
                    darr[tx][ty] += d;
                    arr[i][j] -= d;
                }
            }
        }
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                arr[i][j] += darr[i][j];
        i = w-1, j = 1, k = 0, a = 0;
        nx[1] = -1, nx[3] = 1;
        while(i != w - 1 or j != 0) {
            int d = arr[i][j];
            arr[i][j] = a;
            int tx = i + nx[k];
            int ty = j + ny[k];
            if(tx < 0 or tx >= r or ty < 0 or ty >= c) k++;
            i += nx[k];
            j += ny[k];
            a = d;
        }
        i = w, j = 1, k = 0, a = 0;
        nx[1] = 1, nx[3] = -1;
        while(i != w or j != 0) {
            int d = arr[i][j];
            arr[i][j] = a;
            int tx = i + nx[k];
            int ty = j + ny[k];
            if(tx < 0 or tx >= r or ty < 0 or ty >= c) k++;
            i += nx[k];
            j += ny[k];
            a = d;
        }
        // for(i=0;i<r;i++) {
        //     for(j=0;j<c;j++)
        //         cout << arr[i][j];
        //     cout << endl;
        // }
        // cout << endl;
    }
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            ans += arr[i][j];
    cout << ans + 2;
    return 0;
}