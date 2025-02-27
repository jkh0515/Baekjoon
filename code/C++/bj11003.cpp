//11003 최솟값 찾기 - C++17
//메모리 : 100452KB / 시간 : 1844ms
//2024년 7월 6일 22:49:35

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> ii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int i, l, m, t;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    cin >> l >> m;
    for(i=1;i<=l;i++) {
        cin >> t;
        pq.push({t, i});
        while(pq.top().second <= i-m)
            pq.pop();
        cout << pq.top().first << " ";
    }
    return 0;
}