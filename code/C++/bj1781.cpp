//1781 컵라면 - C++17
//메모리 : 9784KB / 시간 : 68ms
//2024년 5월 17일 00:45:01

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, a, b, i, j, ans = 0;
    vector<int> vt[200001];
    priority_queue<int> pq;
    cin >> n;
    for(i=0;i<n;i++) {
        cin >> a >> b;
        vt[a].push_back(b);
    }
    for(i=n;i>=1;i--) {
        for(j=0;j<vt[i].size();j++)
            pq.push(vt[i][j]);
        if(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;
    return 0;
}