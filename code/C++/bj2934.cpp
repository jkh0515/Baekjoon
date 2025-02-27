//2934 LRH 식물 - C++17
//메모리 : 2800KB / 시간 : 32ms
//2024년 7월 5일 01:27:34

#include <iostream>
#include <vector>
using namespace std;

long long arr[100001], n;

void update(int idx, int diff) {
    while(idx <= 100001) {
        arr[idx] += diff;
        idx += idx & -idx;
    }
} 

long long sum(int idx) {
    long long ans = 0;
    while(idx > 0) {
        ans += arr[idx];
        idx -= idx & -idx;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int a, b, as, bs, i;
    cin >> n;
    for(i=0;i<n;i++) {
        cin >> a >> b;
        as = sum(a), bs = sum(b);
        cout << as + bs << "\n";
        update(a, -as);
        update(a + 1, as + 1);
        update(b, -bs - 1);
        update(b + 1, bs);
    }
    return 0;
}