//3109 빵집 - C++17
//메모리 : 21688KB / 시간 : 212ms
//2024년 8월 2일 23:42:13

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int r, c, i, j, ans = 0, arr[10000][500] = {0}, nx[] = {-1, 0, 1};
string str;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> r >> c;
    for(i=0;i<r;i++) {
        cin >> str;
        for(j=0;j<c;j++) {
            arr[i][j] = str[j] - '.';
            // cout << arr[i][j] << " ";
        }
        // cout << endl;
    }
    for(i=0;i<r;i++) {
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {i, 0}});
        while(!pq.empty()) {
            int t = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            // cout << t << " " << x << " " << y << endl;
            pq.pop();
            if(arr[x][y] != 0) continue;
            arr[x][y] = 'x'-'.';
            if(y == c - 1) {
                ans++;
                break;
            }
            for(j=0;j<3;j++) {
                int tx = x + nx[j], ty = y + 1;
                if(tx < 0 or tx >= r or ty < 0 or ty >= c) continue;
                if(arr[tx][ty] == 0) {
                    pq.push({t + 1000 - j, {tx, ty}});
                    // cout << t - 1000 - j << " " << tx << " " << ty << endl;
                }
            }
        }
    }
    cout << ans;
    return 0;
}