//2638 치즈 - C++17
//메모리 : 2156KB / 시간 : 36ms
//2024년 5월 15일 22:46:06

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int arr[100][100], i, j, n, m, t, ans = 0;
    int nx[] = {1, -1, 0, 0}, ny[] = {0, 0, 1, -1};
    cin >> n >> m;
    vector<pair<int, int>> vt;
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            cin >> t;
            arr[i][j] = t;
            if(t == 1) vt.push_back({i, j});
        }
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(i=0;i<4;i++) {
            int tx = x + nx[i];
            int ty = y + ny[i];
            if(tx < 0 or tx >= n or ty < 0 or ty >= m) continue;
            if(arr[tx][ty] == 0) {
                arr[tx][ty] = -1;
                q.push({tx, ty});
            }
        }
    }
    while(vt.size() > 0) {
        // ans++;
        vector<pair<int, pair<int, int>>> del;
        for(i=0;i<vt.size();i++) {
            int x = vt[i].first;
            int y = vt[i].second;
            int h = 0;
            for(j=0;j<4;j++) {
                int tx = x + nx[j];
                int ty = y + ny[j];
                if(tx < 0 or tx >= n or ty < 0 or ty >= m) continue;
                if(arr[tx][ty] == -1) h++;
            }
            if(h >= 2) del.push_back({i, {x, y}});
        }
        while(del.size() > 0) {
            int idx = del.back().first;
            int x = del.back().second.first;
            int y = del.back().second.second;
            del.pop_back();
            arr[x][y] = -1;
            vt.erase(vt.begin()+idx);
            for(j=0;j<4;j++) {
                int tx = x + nx[j];
                int ty = y + ny[j];
                if(tx < 0 or tx >= n or ty < 0 or ty >= m) continue;
                if(arr[tx][ty] == 0) {
                    queue<pair<int, int>> dq;
                    dq.push({tx, ty});
                    arr[tx][ty] = -1;
                    while(!dq.empty()) {
                        int ttx = dq.front().first;
                        int tty = dq.front().second;
                        dq.pop();
                        for(i=0;i<4;i++) {
                            int tttx = ttx + nx[i];
                            int ttty = tty + ny[i];
                            if(tttx < 0 or tttx >= n or ttty < 0 or ttty >= m) continue;
                            if(arr[tttx][ttty] == 0) {
                                arr[tttx][ttty] = -1;
                                dq.push({tttx, ttty});
                            }
                        }
                    }
                }
            }
        }
        // for(int k=0;k<n;k++) {
        //     for(int l=0;l<m;l++)
        //         cout << arr[k][l] << " ";
        //     cout << endl;
        // }
        // cout << endl;
        ans++;
    }
    cout << ans;
    return 0;
}