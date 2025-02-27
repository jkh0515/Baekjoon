//1105 팔 - C++17
//메모리 : 2024KB / 시간 : 0ms
//2024년 7월 9일 23:51:35

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string a, b;
    int ans = 0;
    bool ck = false;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if(b.size() > a.size()) ck = true;
    for(int i=a.size()-1;i>=0;i--) {
        // cout << ck << " " << a[i] << " " << b[i] << " " << ans << endl;
        if(ck) break;
        if(a[i] == b[i] and a[i] == '8') ans++;
        else if(a[i] != b[i]) ck = true;
    }
    cout << ans;
    return 0;
}