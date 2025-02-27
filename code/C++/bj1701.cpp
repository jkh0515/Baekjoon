//1701 Cubeditor - C++17
//메모리 : 2024KB / 시간 : 88ms
//2024년 3월 6일 00:56:34

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str, tstr;
    cin >> str;
    int i, j, k, tm, m = str.size(), ans = 0;
    for(k=m;k>=2;k--) {
        if(ans >= k) break;
        tstr = str.substr(m-k, k);
        tm = tstr.size();
        // cout << tstr << " " << endl;
        vector<int> vt(tm, 0);
        for(i=m-k+1,j=0;i<=tm+m-k;i++) {
            // cout << str[i] << " " << tstr[j] << endl;
            while(j > 0 and str[i] != tstr[j])
                j = vt[j - 1];
            if(str[i] == tstr[j])
                vt[i-m+k] = ++j;
        }
        for(i=0;i<tm;i++)
            ans = max(ans, vt[i]);
            // cout << vt[i] << " ";
        // cout << endl;
    }
    cout << ans;
    return 0;
}