//2568 전깃줄 - 2 - C++17
//메모리 : 6008KB / 시간 : 36ms
//2024년 5월 28일 22:40:04

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, i, a, b, p, t, prev[500001] = {0};
    bool ck[500001] = {false};
    vector<int> rvt(1, 0), lvt(1, 0);
    vector<pair<int, int>> vt;
    cin >> n;
    for(i=0;i<n;i++) {
        cin >> a >> b;
        vt.push_back({a, b});
    }
    sort(vt.begin(), vt.end());
    for(i=0;i<n;i++) {
        a = vt[i].first, b = vt[i].second;
        t = upper_bound(lvt.begin(), lvt.end(), b) - lvt.begin();
        if(t == lvt.size()) {
            rvt.push_back(0);
            lvt.push_back(0);
        }
        prev[a] = rvt[t-1];
        rvt[t] = a;
        lvt[t] = b;
    }
    p = rvt.back();
    while(p != 0) {
        ck[p] = true;
        p = prev[p];
    }
    cout << n - rvt.size() + 1 << "\n";
    for(i=0;i<n;i++) {
        t = vt[i].first;
        if(!ck[t]) cout << t << "\n";
    }
    return 0;
}