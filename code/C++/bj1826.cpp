//1826 연료 채우기 - C++17
//메모리 : 2292KB / 시간 : 4ms
//2024년 7월 15일 00:16:14

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int i, n, a, b, l, p, ans = 0;
    priority_queue<pair<int, int>> oil;
    priority_queue<int> plus;
    cin >> n;
    for(i=0;i<n;i++) {
        cin >> a >> b;
        oil.push({-a, b});
    }
    cin >> l >> p;
    for(i=1;i<l;i++) {
        p--;
        if(i == -oil.top().first) {
            plus.push(oil.top().second);
            oil.pop();
        }
        if(p == 0) {
            if(plus.empty()) break;
            p += plus.top();
            plus.pop();
            ans++;
        }
    }
    if(i < l) cout << "-1";
    else cout << ans;
    return 0;
}