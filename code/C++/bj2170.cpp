//2170 선 긋기 - C++17
//메모리 : 14436KB / 시간 : 424ms
//2024년 5월 19일 00:35:03

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, a, b, ta, tb, i;
    long ans = 0;
    cin >> n;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for(i=0;i<n;i++) {
        cin >> a >> b;
        pq.push({a, b});
    }
    ta = pq.top().first;
    tb = pq.top().second;
    pq.pop();
    while(!pq.empty()) {
        a = pq.top().first;
        b = pq.top().second;
        pq.pop();
        if(tb >= a) tb = max(tb, b);
        else {
            ans += tb - ta;
            ta = a;
            tb = b;
        }
    }
    cout << ans + (tb - ta);
    return 0;
}