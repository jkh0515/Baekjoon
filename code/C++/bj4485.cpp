//4485 녹색 옷 입은 애가 젤다지? - C++17
//메모리 : 2020KB / 시간 : 8ms
//2024년 2월 8일 22:52:04

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, pair<int, int>> iii;

int main() {
    int n, a = 0, nx[] = {1, -1, 0, 0}, ny[] = {0, 0, 1, -1};
    while(1) {
        cin >> n;
        if(n == 0) break;
        a++;
        int i, j, arr[125][125], node[125][125];
        priority_queue<iii> pq;
        for(i=0;i<n;i++) {
            for(j=0;j<n;j++) { 
                cin >> arr[i][j];
                node[i][j] = -1e9;
            }
        }
        node[0][0] = arr[0][0]*-1;
        pq.push({arr[0][0]*-1, {0, 0}});
        while(!pq.empty()) {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int w = pq.top().first;
            pq.pop();
            if(node[x][y] < w) continue;
            if(x == n-1 and y == n-1) break;
            for(i=0;i<4;i++) {
                int tx = x + nx[i];
                int ty = y + ny[i];
                if(tx < 0 or tx >= n or ty < 0 or ty >= n) continue;
                int tw = w - arr[tx][ty];
                if(node[tx][ty] < tw) {
                    node[tx][ty] = tw;
                    pq.push({tw, {tx, ty}});
                }
            }
        }
        cout << "Problem " << a << ": " << node[n-1][n-1]*-1 << "\n";
    }
    return 0;
}
