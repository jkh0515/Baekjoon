//14245 XOR - C++17
//메모리 : 5928KB / 시간 : 188ms
//2024년 6월 30일 23:11:46

#include <iostream>
using namespace std;

long long tr[500001], n;

void update(int idx, int diff) {
    while(idx <= n) {
        tr[idx] ^= diff;
        idx += idx & -idx;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    long long i, m, a = 0, b, c, d; 
    cin >> n;
    for(i=1;i<=n;i++) {
        cin >> b;
        update(i, b ^ a);
        a = b;
    }
    cin >> m;
    for(i=0;i<m;i++) {
        cin >> a >> b;
        if(a == 1) {
            cin >> c >> d;
            update(b+1, d);
            update(c+2, d);
        }
        else {
            long long ans = 0, idx = b + 1;
            while(idx > 0) {
                ans ^= tr[idx];
                idx -= idx & -idx;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}