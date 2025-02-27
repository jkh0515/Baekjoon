//1584 게임 - C++17
//메모리 : 3864KB / 시간 : 32ms
//2024년 2월 10일 18:17:28

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int death, danger, x1, y1, x2, y2, i, j;
    int arr[501][501] = {0}, node[501][501];
    int nx[] = {1, -1, 0, 0}, ny[] = {0, 0, 1, -1};
    fill(&node[0][0], &node[500][500]+1, -1e9);
    priority_queue<pair<int, pair<int, int>>> pq;
    cin >> danger;
    while(danger--) {
        cin >> x1 >> y1 >> x2 >> y2;
        for(i=min(x1, x2);i<=max(x1, x2);i++)
            for(j=min(y1, y2);j<=max(y1, y2);j++)
                arr[i][j] = 1;
    }
    cin >> death;
    while(death--) {
        cin >> x1 >> y1 >> x2 >> y2;
        for(i=min(x1, x2);i<=max(x1, x2);i++)
            for(j=min(y1, y2);j<=max(y1, y2);j++)
                arr[i][j] = 2;
    }
    pq.push({0, {0, 0}});
    node[0][0] = 0;
    while(!pq.empty()) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int w = pq.top().first;
        pq.pop();
        if(x == 500 and y == 500) break;
        if(node[x][y] < w) continue;
        for(i=0;i<4;i++) {
            int tx = x + nx[i];
            int ty = y + ny[i];
            if(tx < 0 or tx > 500 or ty < 0 or ty > 500 or arr[tx][ty] == 2) continue;
            int tw = w - arr[tx][ty];
            if(node[tx][ty] < tw) {
                pq.push({tw, {tx, ty}});
                node[tx][ty] = tw;
            }
        }
    }
    if(node[500][500] == -1e9) cout << -1;
    else cout << node[500][500] * -1;
    return 0;
}