//1132 합 - C++17
//메모리 : 2216KB / 시간 : 0ms
//2024년 8월 5일 00:24:40

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    long n, i, j, now = 10, ans = 0, arr[10] = {0}, zero[10] = {0}, match[10] = {0};
    string str;
    vector<string> strvt;
    vector<pair<long, pair<long, long>>> vt;
    cin >> n;
    for(i=0;i<n;i++) {
        cin >> str;
        zero[str[0]-'A'] = -1;
        for(j=str.size()-1;j>=0;j--) {
            arr[str[j]-'A'] -= pow(10, str.size() - j);
        }
        strvt.push_back(str);
    }
    for(i=0;i<10;i++) {
        if(arr[i] != 0)
            vt.push_back({arr[i], {i, zero[i]}});
    }
    sort(vt.begin(), vt.end());
    if(vt.size() == 10) {
        for(i=9;i>=0;i--) {
            if(vt[i].second.second == 0) {
                match[vt[i].second.first] = 1 + '0';
                break;
            }
        }
    }
    for(i=0;i<vt.size();i++) {
        // cout << vt[i].first << " " << vt[i].second.first << " " << vt[i].second.second << endl;
        if(match[vt[i].second.first] != 0) continue;
        match[vt[i].second.first] = now + '0';
        now--;
    }
    for(i=0;i<n;i++) {
        for(j=0;j<strvt[i].size();j++)
            strvt[i][j] = match[strvt[i][j]-'A'] - 1;
        // cout << strvt[i] << endl;
        ans += stol(strvt[i]);
    }
    // for(i=0;i<vt.size();i++)
    //     cout << vt[i].first << " " << vt[i].second.first << " " << vt[i].second.second << " " << match[vt[i].second.first] - '1' << endl;
    cout << ans;
    return 0;
}