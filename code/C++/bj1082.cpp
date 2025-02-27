//1082 방 번호 - C++17
//메모리 : 55816KB / 시간 : 424ms
//2024년 3월 9일 21:54:53

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int arr[10], narr[10];
vector<string> vt;

bool cmp(string &a, string &b) {
    if(a.size() != b.size()) return a.size()>b.size();
    return a>b;
}

void cal(string str, int m, int idx) {
    vt.push_back(str);
    // cout << str << " " << m << " " << idx << endl;
    if(idx == -1 or m == 0 or (str.size() != 0 and str[0] == '0')) return;
    if(m >= arr[idx]) cal(str+to_string(idx), m-arr[idx], idx);
    cal(str, m, idx-narr[idx]-1);
    return;
}

int main() {
    int n, m, i;
    cin >> n;
    for(i=0;i<n;i++)
        cin >> arr[i];
    int j = 51;
    for(i=n-1;i>0;i--) {
        j = min(j, arr[i]);
        if(arr[i-1] >= j) {
            narr[i-1] = 1;
        }
    }
    for(i=0;i<n-1;i++) {
        while(i < n and narr[++i] != 0) {
            narr[i] += narr[i-1];
            narr[i-1] = 0;
        }
        narr[i] = narr[i-1];
        narr[i-1] = 0;
    }
    cin >> m;
    cal("", m, n-1);
    sort(vt.begin(), vt.end(), cmp);
    cout << vt[0];
    return 0;
}