//2166 다각형의 면적 - C++17
//메모리 : 2288KB / 시간 : 0ms
//2024년 5월 17일 23:26:28

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cout << fixed;
    cout.precision(1);
    int i, n, a, b;
    double ans = 0, ax, ay, bx, by, cx, cy;
    vector<pair<int, int>> vt;
    cin >> n >> ax >> ay;
    for(i = 1; i < n; i++) {
        cin >> a >> b;
        vt.push_back({a, b});
    }
    for(i = 0; i < n - 2; i++) {
        bx = vt[i].first;
        by = vt[i].second;
        cx = vt[i+1].first;
        cy = vt[i+1].second;
        ans += ax * by + bx * cy + cx * ay - bx * ay - cx * by - ax * cy;
    }
    cout << abs(ans / 2);
    return 0;
}