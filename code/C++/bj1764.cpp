//1764 듣보잡 - C++17
//메모리 : 7580KB / 시간 : 36ms
//2024년 1월 24일 18:20:22

#include <iostream>

#include <map>

#include <vector>

#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    int n, m, i, a=0;

    vector<string> vt;

    string str;

    map<string, int> ma;

    cin >> n >> m;

    for(i=0;i<n;i++) {

        cin >> str;

        ma[str]++;

    }

    for(i=0;i<m;i++) {

        cin >> str;

        if(ma.find(str) != ma.end()) {

            a++;

            vt.push_back(str);

        }

    }

    sort(vt.begin(), vt.end());

    cout << a << "\n";

    for(i=0;i<a;i++)

        cout << vt[i] << "\n";

    return 0;

}