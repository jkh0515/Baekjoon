//16566 카드 게임 - C++17
//메모리 : 51304KB / 시간 : 828ms
//2024년 5월 25일 00:13:23

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    vector<int> vt, ck;
    int n, m, k, i, t, w;
    cin >> n >> m >> k;
    for(i=0;i<=m+1;i++)
        ck.push_back(i);
    for(i=0;i<m;i++) {
        cin >> t;
        vt.push_back(t);
    }
    sort(vt.begin(), vt.end());
    while(k--) {
        cin >> t;
        w = upper_bound(vt.begin(), vt.end(), t) - vt.begin();
        while(ck[w] != w) {
            ck[w] = ck[w + 1];
            w = ck[w];
        }
        ck[w] = ck[w+1];
        cout << vt[w] << "\n";
    }
    return 0;
}