//1920 수 찾기 - C++17
//메모리 : 2920KB / 시간 : 52ms
//2024년 4월 22일 03:40:42

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, t;
    vector<int> vt;
    cin >> n;
    while(n--) {
        cin >> t;
        vt.push_back(t);
    }
    sort(vt.begin(), vt.end());
    cin >> m;
    while(m--) {
        cin >> t;
        cout << binary_search(vt.begin(), vt.end(), t) << "\n";
    }
    return 0;
}