//13146 같은 수로 만들기 2 - C++17
//메모리 : 2020KB / 시간 : 136ms
//2024년 4월 20일 00:46:20

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, t;
    long long ans = 0;
    cin >> n;
    vector<int> vt;
    while(n--) {
        cin >> t;
        if(vt.size() > 0) {
            if(vt.back() == t) continue;
            if(vt.back() < t) {
                ans += (long long)t - vt.back();
                while(vt.size() > 0 and vt.back() <= t) vt.pop_back();
            }
        }
        vt.push_back(t);
    }
    while(vt.size() > 1) {
        t = vt.back();
        vt.pop_back();
        ans += (long long)vt.back() - t;
    }
    cout << ans;
}