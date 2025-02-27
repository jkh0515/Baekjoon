//2665 미로만들기 - C++17
//메모리 : 2024KB / 시간 : 0ms
//2024년 2월 4일 01:40:28

#include <iostream>
#include <deque>
using namespace std;
typedef pair<pair<int, int>, int> xyg;

int main() {
    cin.tie(0);
    cout.tie(0);
    int n, i, j;
    int arr[51][51] = {0}, vs[52][52] = {0};
    int cx[] = {1, -1, 0, 0}, cy[] = {0, 0, 1, -1}; 
    string str;
    deque<xyg> dq;
    cin >> n;
    for(i=1;i<=n;i++) {
        cin >> str;
        for(j=1;j<=n;j++) {
            arr[j][i] = (str[j-1]-'0'-1)*1;
            vs[j][i] = 1;
        }
    }
    dq.push_back({{1, 1}, 0});
    vs[1][1] = 0;
    while(!dq.empty()) {
        xyg top = dq.front();
        dq.pop_front();
        int x = top.first.first;
        int y = top.first.second;
        int g = top.second;
        if(x == n and y == n) {
            cout << g;
            break;
        }
        for(i=0;i<4;i++) {
            int nx = x + cx[i];
            int ny = y + cy[i];
            if(vs[nx][ny] == 0) continue;
            vs[nx][ny] = 0;
            if(arr[nx][ny])
                dq.push_back({{nx, ny}, g+1});
            else dq.push_front({{nx, ny}, g});
        }
    }
    return 0;
}
