//1339 단어 수학 - C++17
//메모리 : 2212KB / 시간 : 0ms
//2024년 8월 6일 00:45:55

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    long n, i, j, now = 10, ans = 0, arr[26] = {0}, match[26] = {0};
    string str;
    vector<string> strvt;
    vector<pair<long, long>> vt;
    cin >> n;
    for(i=0;i<n;i++) {
        cin >> str;
        for(j=str.size()-1;j>=0;j--)
            arr[str[j]-'A'] -= pow(10, str.size() - j);
        strvt.push_back(str);
    }
    for(i=0;i<26;i++)
        if(arr[i] != 0)
            vt.push_back({arr[i], i});
    sort(vt.begin(), vt.end());
    for(i=0,now = 10;i<vt.size();i++,now--)
        match[vt[i].second] = now + '0';
    for(i=0;i<n;i++) {
        for(j=0;j<strvt[i].size();j++)
            strvt[i][j] = match[strvt[i][j]-'A'] - 1;
        ans += stol(strvt[i]);
    }
    cout << ans;
    return 0;
}