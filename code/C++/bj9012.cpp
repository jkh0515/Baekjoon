//9012 괄호 - C++17
//메모리 : 2024KB / 시간 : 0ms
//2024년 4월 23일 04:29:03

#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, i;
    string str;
    cin >> n;
    while(n--) {
        int t = 0, ans = 0;
        cin >> str;
        for(i=0;i<str.size();i++) {
            if(str[i] == '(') t++;
            else t--;
            if(t < 0) {
                ans = 1;
                break;
            }
        }
        if(t != 0) ans = 1;
        if(ans == 1) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}