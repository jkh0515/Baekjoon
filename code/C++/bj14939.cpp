//14939 불 끄기 - C++17
//메모리 : 2024KB / 시간 : 0ms
//2024년 5월 26일 00:26:37

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    bool arr[10][10], cp[10][10];
    int i, j, t, c, ans = 101, ni[] = {-1, 0, 0, 0, 1}, nj[] = {0, -1, 0, 1, 0};
    string str;
    for(i=0;i<10;i++) {
        cin >> str;
        for(j=0;j<10;j++)
            arr[i][j] = str[j] - '#';
    }
    for(c=0;c<(1<<10);c++) {
        int n = 0;
        for(i=0;i<10;i++)
            for(j=0;j<10;j++)
                cp[i][j] = arr[i][j];
        for(i=0;i<10;i++) {
            if(c & (1 << i)) {
                n++;
                for(t=0;t<5;t++) {
                    int ti = 0 + ni[t];
                    int tj = i + nj[t];
                    if(ti < 0 or ti >= 10 or tj < 0 or tj >= 10) continue;
                    cp[ti][tj] = !cp[ti][tj];
                }
            }
        }
        for(i=0;i<9;i++) {
            for(j=0;j<10;j++) {
                if(!cp[i][j]) continue;
                n++;
                for(t=0;t<5;t++) {
                    int ti = i + ni[t] + 1;
                    int tj = j + nj[t];
                    if(ti < 0 or ti >= 10 or tj < 0 or tj >= 10) continue;
                    cp[ti][tj] = !cp[ti][tj];
                }
            }
        }
        for(i=0;i<10;i++) {
            if(cp[9][i]) {
                n = 101;
                break;
            }
        }
        ans = min(ans, n);
        // if(n != 101) {
        //     for(int l=0;l<10;l++) {
        //         for(int k=0;k<10;k++)
        //             cout << cp[l][k] << " ";
        //         cout << endl;
        //     }
        //     cout << endl;
        // }
    }
    if(ans == 101) cout << "-1";
    else cout << ans;
    return 0;
}