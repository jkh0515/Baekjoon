//1654 랜선 자르기 - C++17
//메모리 : 2156KB / 시간 : 4ms
//2024년 6월 21일 01:55:03

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    long k, n, i, j, w = 0, ans = 0, idx;
    cin >> k >> n;
    vector<int> vt;
    for(i = k+1; i > 1; i--) {
        cin >> j;
        w = max(j, w);
        vt.push_back(j);
    }
    while(i < w) i <<= 2;
    for(idx = i, i /= 2; ; i /= 2) {
        w = 0;
        for(j = 0; j < k; j++) {
            w += vt[j] / idx;
        }
            // cout << w << " " << idx << "\n";
        if(w >= n) {
            ans = max(ans, idx);
            idx += i;
        }
        else {
            idx -= i;
        }
        if(i == 0) break;
    }
    cout << ans;
    return 0;
}