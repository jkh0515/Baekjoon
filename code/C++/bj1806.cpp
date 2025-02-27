//1806 부분합 - C++17
//메모리 : 2916KB / 시간 : 8ms
//2024년 6월 16일 02:29:48

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, s, i, t, rhs = 0, lhs = 0, sum = 0, ans = 1e9;
    vector<int> vt;
    cin >> n >> s;
    for(i=0;i<n;i++) {
        cin >> t;
        vt.push_back(t);
    }
    for(i=0;i<n;i++) {
        sum += vt[i];
        while(sum - vt[rhs] >= s) {
            sum -= vt[rhs];
            rhs++;
        }
        if(sum >= s) ans = min(ans, i - rhs + 1);
    }
    if(ans == 1e9) cout << "0";
    else cout << ans;
    return 0;
}