//11444 피보나치 수 6 - C++17
//메모리 : 2024KB / 시간 : 0ms
//2024년 5월 11일 23:28:53

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

map<long long, long long> ma;

long long cal(long long n) {
    if(ma.find(n) != ma.end()) return ma[n];
    if(n % 2 == 0) {
        long long mid = n / 2, cm = cal(mid);
        return ma[n] = (cm * (2LL * cal(mid - 1) + cm)) % 1000000007LL;
    }
    long long mid = (n + 1) / 2, cm = cal(mid), cmm = cal(mid - 1);
    return ma[n] = (cm * cm + cmm * cmm) % 1000000007LL;
}

int main() {
    ma[0] = 0, ma[1] = 1, ma[2] = 1;
    long long n;
    cin >> n;
    cout << cal(n);
    return 0;
}