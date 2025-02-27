//13414 수강신청 - C++17
//메모리 : 25756KB / 시간 : 328ms
//2024년 6월 6일 01:43:42

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<string, int>& a, pair<string, int>& b){
	return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int i, n, m;
    string str;
    map<string, int> ma;
    cin >> n >> m;
    for(i=0;i<m;i++) {
        cin >> str;
        ma[str] = i;
    }
    vector<pair<string, int>> vt(ma.begin(), ma.end());
    sort(vt.begin(), vt.end(), comp);
    for(i=0;i<n and i<vt.size();i++)
        cout << vt[i].first << "\n";
    return 0;
}
