//1354 무한 수열 2 - C++17
//메모리 : 413076KB / 시간 : 9292ms
//2024년 3월 9일 00:46:54

#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
map<ll, ll> ma;
int p, q, x, y;

ll cal(ll n) {
    // cout << n << " ";
    if(ma.find(n) != ma.end())
        return ma[n];
    ll a = cal(max(double(0), floor(n/(double)p)-x));
    ll b = cal(max(double(0), floor(n/(double)q)-y));
    // cout << n << " " << a << " " << b << endl;
    ma[n] = ma[max(double(0), floor(n/(double)p)-x)] + ma[max(double(0), floor(n/(double)q)-y)];
    return 0;
}

int main() {
    ll n;
    cin >> n >> p >> q >> x >> y;
    ma[0] = 1;
    cal(n);
    cout << ma[n];
    return 0;
}