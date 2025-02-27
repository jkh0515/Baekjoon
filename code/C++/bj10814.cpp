//10814 나이순 정렬 - C++17
//메모리 : 9848KB / 시간 : 72ms
//2024년 4월 22일 03:49:14

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, string> a, pair<int, string> b) {
    if(a.first >= b.first) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, t;
    string str;
    vector<pair<int, string>> vt;
    cin >> n;
    while(n--) {
        cin >> t >> str;
        vt.push_back({t, str});
    }
    stable_sort(vt.begin(), vt.end(), comp);
    for(n=0;n<vt.size();n++)
        cout << vt[n].first << " " << vt[n].second << "\n";
    return 0;
}