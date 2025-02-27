//11909 배열 탈출 - C++17
//메모리 : 41100KB / 시간 : 1372ms
//2024년 2월 12일 01:28:06

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int arr[2222][2222], node[2222][2222];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, t, i, j;
    int nx[] = {1, 0}, ny[] = {0, 1};
    // vector<int> vt[2222], node[2222];
    priority_queue<pair<int, pair<int, int>>> pq;
    cin >> n;
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            cin >> t;
            arr[i][j] = t;
            node[i][j] = -1e9;
            // vt[i].push_back(t);
            // node[i].push_back(-1e9);
        }
    }
    pq.push({0, {0, 0}});
    node[0][0] = 0;
    while(!pq.empty()) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int w = pq.top().first;
        pq.pop();
        if(x == n-1 and y == n-1) break;
        if(node[x][y] < w) continue;
        for(i=0;i<2;i++) {
            int tx = x + nx[i];
            int ty = y + ny[i];
            if(tx >= n or ty >= n) continue;
            int tw = w;
            if(arr[tx][ty] >= arr[x][y]) tw -= arr[tx][ty] - arr[x][y] + 1;
            if(node[tx][ty] < tw) {
                node[tx][ty] = tw;
                // if(vt[tx][ty] >= vt[x][y]) 
                //     vt[x][y] = vt[tx][ty] + 1;
                pq.push({tw, {tx, ty}});
            }
        }
    }
    // for(i=0;i<n;i++) {
    //     for(j=0;j<n;j++) {
    //         cout << node[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << node[n-1][n-1] * -1;
    return 0;
}