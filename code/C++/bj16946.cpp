//16946 벽 부수고 이동하기 4 - C++17
//메모리 : 6324KB / 시간 : 124ms
//2024년 5월 23일 00:29:53

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int i, j, n, m, w = 1, t, k, x, y, arr[1000][1000];
    int nx[] = {1, -1, 0, 0}, ny[] = {0, 0, 1, -1};
    string str;
    cin >> n >> m;
    vector<pair<int, int>> vt;
    vector<int> black(1, 1);
    for(i=0;i<n;i++) {
        cin >> str;
        for(j=0;j<m;j++)
            arr[i][j] = str[j] - '0';
    }
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            if(arr[i][j] != 0) continue;
            t = 1;
            queue<pair<int, int>> q;
            q.push({i, j});
            arr[i][j] = w * -1;
            while(!q.empty()) {
                x = q.front().first;
                y = q.front().second;
                q.pop();
                for(k=0;k<4;k++) {
                    int tx = x + nx[k];
                    int ty = y + ny[k];
                    if(tx < 0 or tx >= n or ty < 0 or ty >= m) continue;
                    if(arr[tx][ty] == 0) {
                        arr[tx][ty] = w * -1;
                        q.push({tx, ty});
                        t++;
                    }
                }
            }
            w++;
            black.push_back(t);
        }
    }
    for(x=0;x<n;x++) {
        for(y=0;y<m;y++) {
            if(arr[x][y] != 1) continue;
            vector<bool> ck(black.size()+1, false);
            for(k=0;k<4;k++) {
                int tx = x + nx[k];
                int ty = y + ny[k];
                int tw = arr[tx][ty] * -1;
                if(tx < 0 or tx >= n or ty < 0 or ty >= m) continue;
                if(tw > 0 and ck[tw] == false) {
                    ck[tw] = true;
                    arr[x][y] += black[arr[tx][ty] * -1];
                }
            }
            arr[x][y] %= 10;
        }   
    }
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            if(arr[i][j] < 0) cout << "0";
            else cout << arr[i][j];
            // cout << arr[i][j];
        }
        cout << "\n";
    }
    return 0;
}