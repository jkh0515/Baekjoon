//1486 등산 - C++17
//메모리 : 2156KB / 시간 : 8ms
//2024년 2월 7일 01:47:39

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<pair<int, int>, int> iii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, t, d, i, j, ax, ay, ans = 0;
    int arr[25][25] = {0}, node[25][25], node2[25][25];
    int nx[] = {1, -1, 0, 0}, ny[] = {0, 0, 1, -1};
    priority_queue<iii> pq;
    string str;
    cin >> n >> m >> t >> d;
    for(i=0;i<n;i++) {
        cin >> str;
        for(j=0;j<m;j++) {
            if(str[j] <= 'Z') arr[i][j]=str[j]-'A';
            else arr[i][j] = str[j]-'a'+26;
            node[i][j] = -1e9;
            node2[i][j] = -1e9;
        }
    }
    pq.push({{0, 0}, 0});
    node2[0][0] = 0;
    while(!pq.empty()) {
        int x = pq.top().first.first;
        int y = pq.top().first.second;
        int h = pq.top().second;
        pq.pop();
        if(node2[x][y] < h) continue;
        for(i=0;i<4;i++) {
            int tx = x + nx[i];
            int ty = y + ny[i];
            int th = h - 1;
            if(tx < 0 or tx >= n or ty < 0 or tx >= n) continue;
            if(arr[x][y]-arr[tx][ty] > t or arr[x][y]-arr[tx][ty] < t*-1) continue;
            if(arr[tx][ty] < arr[x][y])
                th = h - (arr[tx][ty]-arr[x][y]) * (arr[tx][ty]-arr[x][y]);
            if(th*-1 <= d and node2[tx][ty] < th) {
                node2[tx][ty] = th;
                pq.push({{tx, ty}, th});
            }
        } 
    }
    pq.push({{0, 0}, 0});
    node[0][0] = 0;
    while(!pq.empty()) {
        int x = pq.top().first.first;
        int y = pq.top().first.second;
        int h = pq.top().second;
        pq.pop();
        if(node[x][y] < h) continue;
        for(i=0;i<4;i++) {
            int tx = x + nx[i];
            int ty = y + ny[i];
            int th = h - 1;
            if(tx < 0 or tx >= n or ty < 0 or tx >= n) continue;
            if(arr[x][y]-arr[tx][ty] > t or arr[x][y]-arr[tx][ty] < t*-1) continue;
            if(arr[tx][ty] > arr[x][y])
                th = h - (arr[tx][ty]-arr[x][y]) * (arr[tx][ty]-arr[x][y]);
            if(th*-1 - node2[tx][ty] <= d and node[tx][ty] < th) {
                node[tx][ty] = th;
                pq.push({{tx, ty}, th});
            }
        }
    }
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            if(node[i][j] == -1e9) continue;
            if(ans < arr[i][j]) {
                ans = arr[i][j];
                ax = i;
                ay = j;
            }
        }
    }
    cout << arr[ax][ay];
    return 0;
}