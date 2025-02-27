//20129 뒤집힌 계산기 - C++17
//메모리 : 102272KB / 시간 : 216ms
//2024년 2월 27일 22:39:10

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    bool arr[16] = {0};
    int pm[4];
    arr[1] = 1, arr[0] = 1, arr[5] = 1, arr[3] = 1;
    string temp = "", str, pr[4] = {"+", "-", "*", "/"};
    vector<string> vt, ans;
    cin >> pm[0] >> pm[1] >> pm[2] >> pm[3] >> str;
    for(int i=0;i<str.size();i++) {
        while(i < str.size() and !arr[str[i]-42])
            temp += str[i++];
        vt.push_back(to_string(stol(temp)));
        if(i >= str.size()) break;
        if(str[i] == '+') vt.push_back("+");
        else if(str[i] == '-') vt.push_back("-");
        else if(str[i] == '*') vt.push_back("*");
        else vt.push_back("/");
        temp = "";
    }
    for(int i=4;i>=1;i--) {
        int prime = 0;
        for(int j=0;j<4;j++) 
            if(pm[j] == i) prime = j;
        ans.clear();
        ans.push_back(vt.back());
        for(int j=vt.size()-2;j>=0;j--) {
            ans.push_back(vt[j]);
            if(j % 2 == 1 and ans.back() == pr[prime]) {
                long long b = stol(vt[--j]);
                ans.pop_back();
                long long a = stol(ans.back());
                ans.pop_back();
                if(prime == 0) ans.push_back(to_string(a+b));
                else if(prime == 1) ans.push_back(to_string(a-b));
                else if(prime == 2) ans.push_back(to_string(a*b));
                else ans.push_back(to_string(a/b));
                // cout << a << " " << b << " " << ans.back() << endl;
            }
        }
        reverse(ans.begin(), ans.end());
        vt = ans;
        // for(int j=0;j<ans.size();j++)
        //     cout << ans[j] << " ";
        // cout << endl;
    }
    cout << stol(vt.back());
    return 0;
}
