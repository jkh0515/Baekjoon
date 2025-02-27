//9935 문자열 폭발 - C++17
//메모리 : 6004KB / 시간 : 76ms
//2024년 2월 26일 23:29:30

#include <iostream>
#include <vector>
using namespace std;

int main() {
    string str, bomb;
    cin >> str >> bomb;
    vector<char> vt;
    int bs = bomb.size(), i = bs, ch;
    for(int i=0;i<str.size();i++) {
        vt.push_back(str[i]);
        if(i > bs - 2) {
            ch = 1;
            for(int j=1;j<=bs;j++) {
                if(vt[vt.size()-j] != bomb[bs-j]) {
                    ch = 0;
                    break;
                }
            }
            if(ch) for(int j=0;j<bs;j++)
                    vt.pop_back();
        }
    }
    if(vt.size() == 0) cout << "FRULA";
    else for(int i=0;i<vt.size();i++)
        cout << vt[i];
    return 0;
}