//1400 화물차 - C++17
//메모리 : 2028KB / 시간 : 0ms
//2024년 2월 10일 15:28:51

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m, i, j;
    string str, b;
    while(1) {
        cin >> n >> m;
        if(n + m == 0) break;
        int arr[20][20], node[20][20];
        int sn = 0, a, c, d, sa[10];
        int nx[] = {1, -1, 0, 0}, ny[] = {0, 0, 1, -1};
        vector<pair<int, int>> sign, ab(2, {0, 0});
        priority_queue<pair<int , pair<int, int>>> pq;
        for(i=0;i<n;i++) {
            cin >> str;
            for(j=0;j<m;j++) {
                node[i][j] = -1e9;
                arr[i][j] = str[j] - 36;
                if(arr[i][j] == -1) continue;
                if(arr[i][j] == 10) arr[i][j] = -2;
                else if(arr[i][j] < 29) {
                    arr[i][j] -= 12;
                    sn++;
                }
                else {
                    ab[arr[i][j]-29] = {i, j};
                    arr[i][j] = -1;
                }
            }
        }
        for(i=0;i<sn;i++) {
            cin >> a >> b >> c >> d;
            sa[a] = (b != "-");
            if(sa[a]) sign.push_back({d, c + d});
            else sign.push_back({c, c + d});
        }
        node[ab[0].first][ab[0].second] = 0;
        pq.push({0, ab[0]});
        while(!pq.empty()) {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int w = pq.top().first;
            pq.pop();
            if(node[x][y] < w) continue;
            for(i=0;i<4;i++) {
                int tx = x + nx[i];
                int ty = y + ny[i];
                int idx = arr[tx][ty];
                if(tx < 0 or tx >= n or ty < 0 or ty >= m or arr[tx][ty] == -2) continue;
                if(idx >= 0) {
                    int nd = (i/2 != sa[idx]); // 0: not 1: ok 지금 방향이 처음 신호인가 
                    int tw = (w * -1 + 1) % sign[idx].second;
                    if(tw == 0) tw += sign[idx].second;
                    int now = (tw <= sign[idx].first); // 0: not 1: ok 지금 시간이  처음 신호인가 
                    int d = (w * -1 + 1) - (w * -1 + 1) % sign[idx].second + sign[idx].second + 1;
                    if(!nd) d = (w * -1 + 1) - (w * -1 + 1) % sign[idx].second + sign[idx].first + 1;
                    if((w * -1 + 1) % sign[idx].second == 0) d -= sign[idx].second;
                    if(nd != now and node[tx][ty] < d * -1) {
                        node[tx][ty] = d * -1;
                        pq.push({d * -1, {tx, ty}});
                        // cout << "d : " << d << " tx: " << tx << " ty: " << ty << " node: " << node[tx][ty] << " tw: " << tw << endl;
                    }
                    else if(nd == now and node[tx][ty] < w - 1) {
                        node[tx][ty] = w - 1;
                        pq.push({w - 1, {tx, ty}});
                    }
                } 
                else if(node[tx][ty] < w - 1) {
                    node[tx][ty] = w - 1;
                    pq.push({w - 1, {tx, ty}});
                    // cout << w-1 << " " << tx << " " << ty << endl;
                }
            }
        }
        // for(i=0;i<n;i++) {
        //     for(j=0;j<m;j++) {
        //         if(node[i][j] == -1e9) cout << "00 ";
        //         else if(node[i][j] == 0) cout << "01 ";
        //         else cout << node[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        if(node[ab[1].first][ab[1].second] == -1e9) cout << "impossible\n";
        else cout << node[ab[1].first][ab[1].second]*-1 << "\n";
    }
    return 0;
}