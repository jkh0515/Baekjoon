//6087 레이저 통신 - C++17
//메모리 : 2024KB / 시간 : 0ms
//2024년 2월 17일 02:40:09

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int h, w, i, j, ax = -1, ay, bx, by;
    string str;
    int arr[101][101], node[101][101];
    int nx[] = {1, -1, 0, 0}, ny[] = {0, 0, 1, -1};
    cin >> w >> h;
    for(i=0;i<h;i++) {
        cin >> str;
        for(j=0;j<w;j++) {
            arr[i][j] = str[j]-46;
            node[i][j] = -1e9;
            if(arr[i][j] > 0) {
                if(ax < 0) {ax = i; ay = j;}
                else {bx = i; by = j;}
            }
        }
    }
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {ax, ay}});
    node[ax][ay] = 0;
    while(!pq.empty()) {
        int m = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        if(x == bx and y == by) break;
        if(node[x][y] < m) continue;
        for(i=0;i<4;i++) {
            int tx = x + nx[i];
            int ty = y + ny[i];
            int tm = m - 1;
            while(1) {
                if(tx < 0 or tx >= h or ty < 0 or ty >= w or arr[tx][ty] < 0) break;
                if(node[tx][ty] == -1e9) {
                    node[tx][ty] = tm;
                    pq.push({tm, {tx, ty}});
                }
                tx += nx[i];
                ty += ny[i];
            }
        }
    }
    cout << node[bx][by]*-1-1;
    // for(i=0;i<h;i++) {
    //     for(j=0;j<w;j++) {
    //         if(node[i][j] == -1e9) cout << "00 ";
    //         else cout << node[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}
