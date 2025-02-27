//10026 적록색약 - C++17
//메모리 : 2024KB / 시간 : 0ms
//2024년 5월 10일 00:54:19

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, i, j, k, a = 1, b = 1, nx[] = {0, 0, 1, -1}, ny[] = {1, -1, 0, 0}; 
    int arr[100][100], p[100][100] = {0}, np[100][100] = {0};
    string str;
    cin >> n;
    for(i=0;i<n;i++) {
        cin >> str;
        for(j=0;j<n;j++)
            arr[i][j] = str[j]-'A';
    }
    queue<pair<int, int>> q;
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            if(p[i][j] != 0) continue;
            q.push({i, j});
            int f = arr[i][j];
            while(!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(k=0;k<4;k++) {
                    int tx = x + nx[k];
                    int ty = y + ny[k];
                    if(tx < 0 or tx >= n or ty < 0 or ty >= n) continue;
                    if(p[tx][ty] == 0 and arr[tx][ty] == f) {
                        p[tx][ty] = a;
                        q.push({tx, ty});
                    }
                }
            }
            a++;
        }
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(arr[i][j] == 'R'-'A') arr[i][j] = 'G'-'A';
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            if(np[i][j] != 0) continue;
            q.push({i, j});
            int f = arr[i][j];
            while(!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(k=0;k<4;k++) {
                    int tx = x + nx[k];
                    int ty = y + ny[k];
                    if(tx < 0 or tx >= n or ty < 0 or ty >= n) continue;
                    if(np[tx][ty] == 0 and arr[tx][ty] == f) {
                        np[tx][ty] = b;
                        q.push({tx, ty});
                    }
                }
            }
            b++;
        }
    }
    cout << a - 1 << " " << b - 1;
    return 0;
}