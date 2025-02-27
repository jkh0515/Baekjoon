//2151 거울 설치 - C++17
//메모리 : 2028KB / 시간 : 0ms
//2024년 2월 9일 23:20:27

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int n, i, j;
    int nx[] = {1, -1, 0, 0}, ny[] = {0, 0, 1, -1};
    int arr[50][50], node[50][50];
    vector<pair<int, int>> sh;
    priority_queue<pair<int, pair<int, int>>> pq;
    string str;
    cin >> n;
    for(i=0;i<n;i++) {
        cin >> str;
        for(j=0;j<n;j++) {
            arr[i][j] = str[j] - 33;
            node[i][j] = -1e9;
            if(arr[i][j] == 2) {
                sh.push_back({i, j});
                arr[i][j] = 0;
            }
        }
    }
    pq.push({0, sh[0]});
    node[sh[0].first][sh[0].second] = 0;
    while(!pq.empty()) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int w = pq.top().first;
        pq.pop();
        if(x == sh[1].first and y == sh[1].second) break;
        if(node[x][y] < w) continue;
        for(i=0;i<4;i++) {
            int tx = x + nx[i];
            int ty = y + ny[i];
            while(1) {
                if(tx < 0 or tx >= n or ty < 0 or ty >= n) break;
                if(arr[tx][ty] == 9) break;
                if(arr[tx][ty] == 0 and node[tx][ty] < w - 1) {
                    node[tx][ty] = w - 1;
                    pq.push({w - 1, {tx, ty}});
                }
                tx += nx[i];
                ty += ny[i];
            }
        }
    }
    cout << node[sh[1].first][sh[1].second]*-1-1;
    // for(i=0;i<n;i++) {
    //     for(j=0;j<n;j++) {
    //         if(node[i][j] == -1e9) cout << "0 ";
    //         else cout << node[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}
