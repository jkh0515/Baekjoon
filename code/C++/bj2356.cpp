//2356 제곱 ㄷㄷ 수 - C++17
//메모리 : 2040KB / 시간 : 0ms
//2024년 6월 27일 00:18:31

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

typedef long long lli;

string cal(string str) {
    for(int i=0;i<str.size();i++) {
        for(int j=i;j<str.size();j++) {
            string tstr = str.substr(i, j-i+1);
            lli n = stoll(tstr), nsqrt = (lli)sqrtl(n);
            if(nsqrt * nsqrt == n) {
                string nstr = to_string(stoll(str.substr(0, j+1)) + (lli)1);
                for(int k=j+1;k<str.size();k++)
                    nstr += '2';
                return cal(nstr);
            }
        }
    }
    return str;
}

int main() {
    string str;
    cin >> str;
    cout << cal(str);
    return 0;
}