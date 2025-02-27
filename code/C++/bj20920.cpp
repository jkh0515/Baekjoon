//20920 영단어 암기는 괴로워 - C++17
//메모리 : 13864KB / 시간 : 116ms
//2024년 3월 24일 02:58:46

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second != b.second)
		return a.second > b.second;
	else if (a.first.length() != b.first.length())
		return a.first.length() > b.first.length();
	else return a.first < b.first;
    // if(a.second == b.second) {
    //     if(a.first.size() == b.first.size()) return a.first > b.first;
    //     else return a.first.size() > b.first.size();
    // }
    // else return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, i;
    string str;
    map<string, int> ma;
    cin >> n >> m;
    for(i=0;i<n;i++) {
        cin >> str;
        if(str.size() < m) continue;
        ma[str]++;
    }
    vector<pair<string, int>> vt(ma.begin(), ma.end());
    sort(vt.begin(), vt.end(), comp);
    for(i=0;i<vt.size();i++)
        cout << vt[i].first << "\n";
    return 0;
}