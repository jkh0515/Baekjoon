//2423 전구를 켜라 - C++17
//메모리 : 5024KB / 시간 : 36ms
//2024년 2월 22일 01:40:06

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m, i, j;
    string str;
    cin >> n >> m;
    int nx[] = {-1, 1, 1, -1}, ny[] = {1, -1, 1, -1};
    int ntx[] = {-1, 0, 0, -1}, nty[] = {0, -1, 0, -1};
    int arr[500][500], spot[501][501];
    priority_queue<pair<int, pair<int, int>>> pq;
    fill(&spot[0][0], &spot[n][m]+1, -1e9);
    for(i=0;i<n;i++) {
        cin >> str;
        for(j=0;j<m;j++)
            arr[i][j] = str[j] % 11 - 3;
    }
    spot[0][0] = 0;
    pq.push({0, {0, 0}});
    while(!pq.empty()) {
        int w = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        if(spot[x][y] < w) continue;
        for(i=0;i<4;i++) {
            int tw = w;
            int tx = x + nx[i];
            int ty = y + ny[i];
            int tnx = x + ntx[i];
            int tny = y + nty[i];
            if(tx < 0 or tx > n or ty < 0 or ty > m) continue;
            if(arr[tnx][tny] and i < 2) tw = w - 1;
            if(not(arr[tnx][tny]) and i > 1) tw = w - 1;
            if(spot[tx][ty] < tw) {
                spot[tx][ty] = tw;
                pq.push({tw, {tx, ty}});
            }
        }
    }
    // cout << " ";
    // for(i=0;i<=n;i++) {
    //     for(j=0;j<=m;j++) {
    //         if(spot[i][j] == -1e9) cout << "none ";
    //         else cout << "  " << spot[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    if(spot[n][m] == -1e9) cout << "NO SOLUTION";
    else cout << spot[n][m] / -1;
    return 0;
}