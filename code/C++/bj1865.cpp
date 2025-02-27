//1865 웜홀 - C++17
//메모리 : 2220KB / 시간 : 32ms
//2024년 5월 15일 00:47:39

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n, m, w, a, b, c, i, j, ans = 0, ck[501];
        cin >> n >> m >> w;
        fill(&ck[0], &ck[501], 1e9);
        vector<pair<pair<int, int>, int>> vt;
        while(m--) {
            cin >> a >> b >> c;
            vt.push_back({{a, b}, c});
            vt.push_back({{b, a}, c});
        }
        while(w--) {
            cin >> a >> b >> c;
            vt.push_back({{a, b}, c * -1});
        }
        for(i=0;i<n;i++) {
            for(j=0;j<vt.size();j++) {
                a = vt[j].first.first;
                b = vt[j].first.second;
                c = vt[j].second;
                ck[b] = min(ck[b], ck[a] + c);
            }
        }
        for(i=0;i<vt.size();i++) {
            a = vt[i].first.first;
            b = vt[i].first.second;
            c = vt[i].second;
            if(ck[b] > ck[a] + c) {
                ans = 1;
                break;
            }
        }
        if(ans == 1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}