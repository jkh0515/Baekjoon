//12851 숨바꼭질 2 - C++17
//메모리 : 2552KB / 시간 : 4ms
//2024년 2월 16일 01:50:40

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, m, i, ai = -1e9, ans;
    int arr[100001] = {0}, route[100001] = {0};
    queue<int> q;
    cin >> n >> m;
    q.push(n);
    route[n] = -1;
    arr[n] = n;
    while(!q.empty()) {
        int t = q.front();
        q.pop();
        // cout << t << " " << route[t] << endl;
        if(route[t] < ai) break;
        if(t == m) {
            ai = route[t];
            ans++;
        }
        for(i=-1;i<=1;i++) {
            int a = t + i;
            if(i == 0) a *= 2;
            if(a >= 0 and a <= 100000 and route[a] == route[t]-1) {
                q.push(a);
                continue;
            }
            if(a < 0 or a > 100000 or route[a] != 0) continue;
            route[a] = route[t]-1;
            arr[a] = t;
            q.push(a);
        }
    }
    cout << ai*-1-1 << "\n" << ans;
    return 0;
}
