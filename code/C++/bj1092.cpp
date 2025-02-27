//1092 배 - C++17
//메모리 : 2160KB / 시간 : 0ms
//2024년 8월 4일 03:56:06

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i, n, m, t, ans = 0, sum = 0;
    vector<int> vt(1, 0);
    priority_queue<int, vector<int>, greater<int>> c, b;
    cin >> n;
    for(i=0;i<n;i++) {
        cin >> t;
        c.push(t);
    }
    cin >> m;
    for(i=0;i<m;i++) {
        cin >> t;
        b.push(t);
    }
    while(!b.empty()) {
        if(c.top() >= b.top()) {
            vt.back()++;
            b.pop();
        }
        else {
            vt.push_back(0);
            c.pop();
            if(c.empty()) {
                ans = -1;
                break;
            }
        }
    }
    if(ans == -1) cout << ans;
    else {
        for(i=vt.size()-1;i>=0;i--) {
            sum += vt[i];
            ans = max(ans, (int)ceil((double)sum / (n - i)));
            // cout << vt[i] << " ";
        }
        // cout << endl;
        cout << ans;
    }
    return 0;
}