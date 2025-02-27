//16975 수열과 쿼리 21 - C++17
//메모리 : 17644KB / 시간 : 44ms
//2024년 6월 30일 00:58:49

#include <iostream>
using namespace std;

long long arr[1000001], tr[1000001], n;

void update(int idx, int diff) {
    while(idx <= n) {
        tr[idx] += diff;
        idx += idx & -idx;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int i, a = 0, b, c, d, m;
    cin >> n;
    for(i=1;i<=n;i++) {
        cin >> b;
        arr[i] = b - a;
        update(i, arr[i]);
        a = b;
    }
    cin >> m;
    for(i=1;i<=m;i++) {
        cin >> a >> b;
        if(a == 1) {
            cin >> c >> d;
            update(b, d);
            update(c+1, -d);
        }
        else {
            long long ans = 0;
            while(b > 0) {
                ans += tr[b];
                b -= b & -b;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}