//19591 독특한 계산기 - C++17
//메모리 : 37448KB / 시간 : 168ms
//2024년 2월 28일 21:15:33

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long cal(string sa, string c, string sb) {
    long long a = stoll(sa), b = stoll(sb);
    if(c == "+") return a + b;
    if(c == "-") return a - b;
    if(c == "*") return a * b;
    return a/b;
}

int main() {
    deque<string> dq;
    // cout << '+'+0 << '-'+0 << '*'+0 << '/'+0;
    string str, t = "";
    cin >> str;
    int pm[48] = {0};
    pm[43] = 2, pm[45] = 3, pm[42] = 4, pm[47] = 5;
    if(str[0] == '-') t += "-";
    for(int i=0;i<str.size();i++) {
        if(i == 0 and str[i] == '-') i++;
        while(str[i] > 47) t += str[i++];
        dq.push_back(to_string(stoll(t)));
        if(i >= str.size()) break;
        if(str[i] == '-') dq.push_back("-");
        else if(str[i] == '+') dq.push_back("+");
        else if(str[i] == '*') dq.push_back("*");
        else dq.push_back("/");
        t = "";
    }
    while(dq.size() > 1) {
        int ds = dq.size(), tp = 0, ap = dq[1][0], bp = dq[ds-2][0];
        long long a = cal(dq[0], dq[1], dq[2]), b = cal(dq[ds-3], dq[ds-2], dq[ds-1]);
        if(pm[ap]/2 > pm[bp]/2) tp = 1;
        else if(pm[ap]/2 == pm[bp]/2 and a >= b) tp = 1;
        if(tp) {
            for(int i=0;i<3;i++) dq.pop_front();
            dq.push_front(to_string(a));
        }
        else {
            for(int i=0;i<3;i++) dq.pop_back();
            dq.push_back(to_string(b));
        }
    }
    cout << stoll(dq[0]);
    return 0;
}
