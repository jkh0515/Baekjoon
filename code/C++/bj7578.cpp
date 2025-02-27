//7578 공장 - C++17
//메모리 : 29428KB / 시간 : 648ms
//2024년 7월 3일 23:27:46

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

long long n, tr[500001];

void update(int idx, long long diff) {
    while(idx <= n) {
        tr[idx] += diff;
        idx += idx & -idx;
    }
}

long long sum(int idx) {
    long long ans = 0;
    while(idx > 0) {
        ans += tr[idx];
        idx -= idx & -idx;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int i, t;
    long long ans = 0;
    map<int, int> ma;
    cin >> n;
    for(i=1;i<=n;i++) {
        cin >> t;
        ma[t] = i;
    }
    for(i=1;i<=n;i++) {
        cin >> t;
        update(ma[t], 1);
        ans += i - sum(ma[t]);
    }
    cout << ans;
    return 0;
}