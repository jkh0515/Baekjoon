//17612 쇼핑몰 - C++17
//메모리 : 5740KB / 시간 : 48ms
//2024년 4월 6일 17:17:49

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
typedef pair<ull, pair<int, int>> lii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ull ans = 0, t = 0;
    int n, k, id, w, i, e = 0;
    priority_queue<int, vector<int>, greater<int>> nli;
    priority_queue<pair<int, int>> eli;
    priority_queue<lii, vector<lii>, greater<lii>> pq;
    cin >> n >> k;
    for(i=1;i<=k;i++)
        nli.push(i);
    for(i=0;i<n;i++) {
        cin >> id >> w;
        if(nli.size() > 1) {
            pq.push({w+t, {nli.top(), id}});
            nli.pop();
            continue;
        }
        pq.push({w+t, {nli.top(), id}});
        nli.pop();
        t = pq.top().first;
        eli.push({pq.top().second.first, pq.top().second.second});
        pq.pop();
        while(pq.size() > 0 and pq.top().first == t) {
            eli.push({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        while(!eli.empty()) {
            e++;
            ans += (ull)e * eli.top().second;
            nli.push(eli.top().first);
            eli.pop();
        }
    }
    while(!pq.empty()) {
        t = pq.top().first;
        eli.push({pq.top().second.first, pq.top().second.second});
        pq.pop();
        while(pq.size() > 0 and pq.top().first == t) {
            eli.push({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        while(!eli.empty()) {
            e++;
            ans += (ull)e * eli.top().second;
            nli.push(eli.top().first);
            eli.pop();
        }
    }
    cout << ans;
}