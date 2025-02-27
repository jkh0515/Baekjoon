//6549 히스토그램에서 가장 큰 직사각형 - C++17
//메모리 : 5220KB / 시간 : 36ms
//2024년 7월 2일 23:35:40

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    long long t, i, s, a, b;
    cin >> t;
    while(t != 0) {
        vector<pair<long long, long long>> vt;
        long long ans = 0;
        cin >> s;
        vt.push_back({s, 0});
        for(i=1;i<t;i++) {
            cin >> s;
            b = i;
            while(vt.back().first > s) {
                a = vt.back().first, b = min(b, vt.back().second);
                ans = max(ans, a * (i - vt.back().second));
                vt.pop_back();
            }
            vt.push_back({s, b});
        }
        while(vt.size() > 0) {
            a = vt.back().first, b = vt.back().second;
            ans = max(ans, a * (t - b));
            vt.pop_back();
        }
        cout << ans << "\n";
        cin >> t;
    }
    return 0;
}