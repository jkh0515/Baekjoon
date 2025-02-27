//12904 A와 B - C++17
//메모리 : 2024KB / 시간 : 0ms
//2024년 4월 26일 00:30:52

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string a, b, c;
    cin >> a >> b;
    while(a.size() < b.size()) {
        c = b[b.size()-1];
        b = b.substr(0, b.size()-1);
        if(c == "B")
            reverse(b.begin(), b.end());
    }
    // cout << a << " " << b << endl;
    if(a == b) cout << "1";
    else cout << "0";
    return 0;
}