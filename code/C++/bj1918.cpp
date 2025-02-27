//1918 후위 표기식 - C++17
//메모리 : 2040KB / 시간 : 0ms
//2024년 5월 14일 00:09:47

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

vector<string> vt;
map<char, int> ci;
map<char, string> cs;
map<string, int> si;
string str, t = "";
int i, nb = 0, mb = 0;

int cal(int nsize, char c) {
    if(nsize < 2) return 0;
    int p = si[vt[nsize-2]];
    if(p == -1 or p < ci[c]) return 0;
    string sa, sb, sc = vt.back();
    vt.pop_back();
    sb = vt.back();
    vt.pop_back();
    sa = vt.back();
    vt.pop_back();
    vt.push_back(sa + sc + sb);
    return cal(nsize-2, c);
}

int fin() {
    if(vt.size() == 1) return 0;
    if(vt[vt.size()-2] == "(") {
        string t = vt.back();
        vt.pop_back();
        vt.pop_back();
        vt.push_back(t);
        if(nb == mb) return fin();
        else return 0;
    }
    string sa, sb, sc = vt.back();
    vt.pop_back();
    sb = vt.back();
    vt.pop_back();
    sa = vt.back();
    vt.pop_back();
    vt.push_back(sa + sc + sb);
    return fin();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ci['+'] = 1, ci['-'] = 1, ci['/'] = 2, ci['*'] = 2;
    cs['+'] = "+", cs['-'] = "-", cs['/'] = "/", cs['*'] = "*", cs['('] = "(";
    si["+"] = 1, si["-"] = 1, si["/"] = 2, si["*"] = 2, si["("] = -1;
    cin >> str;
    str = "(" + str + ")";
    for(i=0;i<str.size();i++) {
        char c = str[i];
        if(c >= 'A' and c <= 'Z') t += c;
        else {
            if(t != "") {
                vt.push_back(t);
                t = "";
            }
            if(c == '(') {
                vt.push_back(cs[c]);
                nb++;
            }
            else if(c == ')') {
                mb++;
                fin();
            }
            else {
                cal(vt.size(), c);
                vt.push_back(cs[c]);
            }
        }
    }
    if(t != "") {
        vt.push_back(t);
        fin();
    }
    cout << vt.back();
    return 0;
}