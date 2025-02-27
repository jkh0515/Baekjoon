//28709 와일드카드 괄호 문자열 - C++17
//메모리 : 3476KB / 시간 : 444ms
//2024년 3월 2일 01:20:54

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int t, q, n, p, s, m, e, i, j;
    string str;
    // cout << '('+0 << " " << ')'+0 << " " << '?'+0 << " " << '*'+0;
    cin >> t;
    while(t--) {
        q = 0, n = 0, s = 0, e = 0, p = 0;
        cin >> str;
        for(i=0;i<str.size();i++) {
            if(s == 0) {
                if(str[i] == 40) n++, p++;
                else if(str[i] == 63) n++, q++;
                else if(str[i] == 41) n--;
                else s += 1, q = 0, n = 0;
                // cout << n;
                if(n < 0) {
                    e = 1;
                    // n = 0;
                    break;
                }
            }
            else {
                if(str[i] == 40) n++;
                else if((str[i] == 41 or str[i] == 63) and n > 0) n--;
                else s += 1, n = 0, q = 0;
            }
        }
        if(s > 0 and n > 0) e = 1;
        if(s == 0 and str.size() % 2 != 0) e = 1;
        else if(s == 0) {
            q = str.size()/2; n = 0;
            for(j=0;j<str.size();j++) {
                if(str[j] == 40) n++;
                else if(str[j] == 41) n--;
                else {
                    if(p < q) n++, p++;
                    else n--;
                }
                if(n < 0) {
                    e = 1;
                    break;
                }
            }
            if(n > 0) e = 1;
        }
        if(e) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}