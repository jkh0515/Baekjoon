//16934 게임 닉네임 - C++17
//메모리 : 39956KB / 시간 : 188ms
//2024년 4월 11일 23:54:21

#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

typedef struct mp {
    map<int, mp> ma;
} mp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    mp head;
    int n, i;
    string str;
    map<string, int> fmap;
    vector<string> vt;
    cin >> n;
    while(n--) {
        cin >> str;
        fmap[str]++;
        mp* now = &head;
        string ans = "";
        for(i=0;i<str.size();i++) {
            int t = str[i] - 'a';
            if(now->ma.find(t) == now->ma.end()) {
                mp newmp;
                now->ma[t] = newmp;
            }
            else ans += str[i];
            now = &now->ma[t];
        }
        if(ans.size() != str.size()) ans += str[ans.size()];
        if(ans.size() == str.size() and fmap[str] > 1) ans += to_string(fmap[str]);
        vt.push_back(ans);
        // cout << ans << "\n";
    }
    for(i=0;i<vt.size();i++)
        cout << vt[i] << "\n";
    return 0;
}