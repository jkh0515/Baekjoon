//16236 아기 상어 - C++17
//메모리 : 2028KB / 시간 : 0ms
//2024년 5월 12일 21:54:49

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> ii;

int n, i, j, t, nsize = 2, eat = 0, ceat = 0, ans = 0, arr[20][20], fish[7];
int nx[] = {-1, 0, 0, 1}, ny[] = {0, -1, 1, 0};

pair<int, ii> findFish(ii xy) {
    bool ck[20][20] = {false};
    priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> q;
    q.push({0, xy});
    pair<int, ii> rt;
    rt = {-1, {-1, -1}};
    ck[xy.first][xy.second] = true;
    while(!q.empty()) {
        int d = q.top().first;
        int x = q.top().second.first;
        int y = q.top().second.second;
        q.pop();
        if(arr[x][y] != 0 and arr[x][y] < nsize) {
            rt = {d, {x, y}};
            break;
        }
        for(i=0;i<4;i++) {
            int tx = x + nx[i];
            int ty = y + ny[i];
            if(tx < 0 or tx >= n or ty < 0 or ty >= n) continue;
            if(arr[tx][ty] <= nsize and ck[tx][ty] == false) {
                ck[tx][ty] = true;
                q.push({d+1, {tx, ty}});
            }
        }
    }
    return rt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ii xy;
    cin >> n;
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            cin >> t;
            arr[i][j] = t;
            if(t == 9) xy = {i, j};
            else fish[t]++;
        }
    }
    ceat = fish[1];
    arr[xy.first][xy.second] = 0;
    while(ceat > 0) {
        pair<int, ii> f = findFish(xy);
        if(f.first == -1) break;
        xy = f.second;
        ans += f.first;
        eat++;
        ceat--;
        arr[xy.first][xy.second] = 0;
        if(eat == nsize) {
            ceat += fish[nsize];
            nsize++;
            eat = 0;
        }
        // cout << xy.first << " " << xy.second << " " << eat << " " << ceat << " " << ans << endl;
    }
    cout << ans;
    return 0;
}