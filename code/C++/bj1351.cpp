//1351 무한 수열 - C++17
//메모리 : 2024KB / 시간 : 0ms
//2024년 3월 7일 21:05:07

#include <iostream>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;
map<ll, ll> ma;
int p, q;

ll cal(ll n) {
    if(ma.find(n) != ma.end())
        return ma[n];
    ll m = cal(floor(n/(double)p)) + cal(floor(n/(double)q));
    ma[n] = cal(floor(n/(double)p)) + cal(floor(n/(double)q));
    // ma[n] = ;
    // cout << n << " " << floor(n/(double)p) << " " << floor(n/(double)q) << " " << m;// << endl;
    // cout << ma[n] << endl;
    return 0;
}

int main() {
    ll n;
    cin >> n >> p >> q;
    ma[0] = 1;
    cal(n);
    cout << ma[n];
    return 0;
}