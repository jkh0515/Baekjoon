//15824 너 봄에는 캡사이신이 맛있단다 - C++17
//메모리 : 8296KB / 시간 : 60ms
//2025년 3월 16일 03:33:36

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    long long n, a, r = 0, m = 0, times = 1, MOD = 1000000007;
    cin >> n;
    vector<long long> input;
    for(int i=0;i<n;i++) {
        cin >> a;
        input.push_back(a);
    }
    sort(input.begin(), input.end());
    for(int i=0;i<n;i++) {
        r += (input[i] % MOD) * (times - 1) % MOD;
        m += (input[n-i-1] % MOD) * (times -1 ) % MOD;
        times = (times * 2) % MOD;
    }
    cout << (r % MOD + MOD - m % MOD) % MOD;
    return 0;
}