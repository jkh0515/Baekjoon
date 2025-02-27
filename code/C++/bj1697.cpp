//1697 숨바꼭질 - C++17
//메모리 : 5492KB / 시간 : 16ms
//2024년 6월 25일 00:14:14

#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int a, b;
    bool ck[100001] = {false};
    cin >> a >> b;
    queue<pair<int, int>> q;
    q.push({a, 0});
    while(1) {
        int t = q.front().first;
        int w = q.front().second;
        q.pop();
        ck[t] = true;
        if(t == b) {
            cout << w;
            break;
        }
        if(ck[t+1] == 0) q.push({t+1, w+1});
        if(t > 0) {
            if(ck[t-1] == 0)q.push({t-1, w+1});
            if(t <= 50000)
                if(ck[t*2] == 0) q.push({t*2, w+1});
        }
    }
    return 0;
}