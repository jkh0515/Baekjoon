//1445 일요일 아침의 데이트 - C++17
//메모리 : 2156KB / 시간 : 32ms
//2024년 2월 7일 18:07:17

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<pair<int, int>, int> iii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    int n, m, i, j, k, sx, sy, rx, ry;
    int arr[50][50] = {0}, ans[50][50];
    int nx[] = {1, -1, 0, 0}, ny[] = {0, 0, 1, -1};
    priority_queue<iii> pq;
    cin >> n >> m;
    for(i=0;i<n;i++) {
        cin >> str;
        for(j=0;j<m;j++) {
            if(str[j] == 'S') {
                arr[i][j] = 1e9;
                sx = i;
                sy = j;
            }
            if(str[j] == 'F') {
                arr[i][j] = 1e9;
                rx = i;
                ry = j;
            }
            if(str[j] == 'g') {
                arr[i][j] = 10000;
                for(k=0;k<4;k++) {
                    int tx = i + nx[k];
                    int ty = j + ny[k];
                    if(tx < 0 or tx >= n or ty < 0 or ty >= m) continue;
                    arr[tx][ty] = max(arr[tx][ty], 1);
                }
            }
            ans[i][j] = -1e9;
        }
    }
    arr[sx][sy] = 0;
    arr[rx][ry] = 0;
    ans[sx][sy] = 0;
    pq.push({{sx, sy}, 0});
    while(!pq.empty()) {
        int x = pq.top().first.first;
        int y = pq.top().first.second;
        int w = pq.top().second;
        pq.pop();
        if(ans[x][y] < w) continue;
        for(i=0;i<4;i++) {
            int tx = x + nx[i];
            int ty = y + ny[i];
            int tw = w - arr[tx][ty];
            if(tx < 0 or tx >= n or ty < 0 or ty >= m) continue;
            if(ans[tx][ty] < tw) {
                pq.push({{tx, ty}, tw});
                ans[tx][ty] = tw;
            }
        }
    }
    cout << (ans[rx][ry]*-1) / 10000 << " " << (ans[rx][ry]*-1)%10000;
}