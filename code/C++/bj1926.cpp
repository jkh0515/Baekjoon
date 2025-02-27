//1926 그림 - C++17
//메모리 : 3772KB / 시간 : 32ms
//2024년 7월 16일 02:06:00

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, i, j, k, ans = 0, arr[500][500] = {0}, nx[] = {1, -1, 0, 0}, ny[] = {0, 0, 1, -1};
    cin >> n >> m;
    vector<int> vt;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            cin >> arr[i][j];
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            if(arr[i][j]) {
                // cout << i << " " << j << endl;
                k = vt.size();
                vt.push_back(1);
                queue<pair<int, int>> q;
                arr[i][j] = 0;
                q.push({i, j});
                while(!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int l=0;l<4;l++) {
                        int tx = x + nx[l];
                        int ty = y + ny[l];
                        if(tx < 0 or tx >= n or ty < 0 or ty >= m) continue;
                        if(arr[tx][ty]) {
                            arr[tx][ty] = 0;
                            vt[k]++;
                            q.push({tx, ty});
                        }
                    }
                }
            }
        }
    }
    for(i=0;i<vt.size();i++)
        ans = max(ans, vt[i]);
    cout << vt.size() << "\n" << ans;
    return 0;
}