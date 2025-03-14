//13334 철로 - C++17
//메모리 : 13476KB / 시간 : 116ms
//2025년 3월 15일 04:49:25

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, a, b, d, r = 0;
    cin >> n;
    map<int, int> inma, outma;
    priority_queue<int, vector<int>, greater<int>> inq, outq;
    vector<pair<int, int>> vt;
    for(int i=0;i<n;i++) {
        cin >> a >> b;
        if(b < a) swap(a, b);
        vt.push_back({a, b});
    }
    cin >> d;
    for(int i=0;i<n;i++) {
        if(vt[i].second - vt[i].first > d) continue;
        inma[vt[i].first]++;
        outma[vt[i].second]++;
    }
    for(auto iter : inma) inq.push(iter.first);
    for(auto iter : outma) outq.push(iter.first);
    if(inq.empty()) {
        cout << r;
        return 0;
    }
    int start = inq.top(), num = inma[start];
    while(!inq.empty()) {
        num -= inma[start];
        start = inq.top();
        inq.pop();
        while(!outq.empty() and start + d >= outq.top()) {
            num += outma[outq.top()];
            outq.pop();
        }
        r = max(r, num);
    }
    cout << r;
    return 0;
}