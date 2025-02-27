//13913 숨바꼭질 4 - C++17
//메모리 : 3468KB / 시간 : 16ms
//2024년 2월 15일 01:28:18

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, m, i;
    int arr[100001] = {0}, route[100001] = {0};
    queue<int> q;
    vector<int> ans;
    cin >> n >> m;
    q.push(n);
    route[n] = -1;
    arr[n] = n;
    while(!q.empty()) {
        int t = q.front();
        q.pop();
        // cout << t << " " << route[t] << endl;
        if(t == m) {
            cout << route[t]*-1-1 << "\n";
            int a = arr[t];
            while(1) {
                ans.push_back(a);
                if(a == n) break;
                a = arr[a];
            }
            for(i=1;i<route[t]*-1;i++) {
                cout << ans.back() << " ";
                ans.pop_back();
            }
            cout << m;
            break;
        }
        for(i=-1;i<=1;i++) {
            int a = t + i;
            if(i == 0) a *= 2;
            if(a < 0 or a > 100000 or route[a] != 0) continue;
            route[a] = route[t]-1;
            arr[a] = t;
            q.push(a);
        }
    }
    return 0;
}
