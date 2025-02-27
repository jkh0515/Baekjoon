//5670 휴대폰 자판 - C++17
//메모리 : 48224KB / 시간 : 544ms
//2024년 5월 20일 03:16:55

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

class trie {
    public:
    int n;
    bool ck[26];
    map<int, trie> ma;
    trie() {
        n = 0;
        fill(&ck[0], &ck[26], false);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cout << fixed, cout.precision(2);
    int t, i, j, k, sum = 0;
    string str;
    while(cin >> t) {
    // cin >> t;
        trie head;
        sum = 0;
        vector<string> vt;
        trie *up = &head;
        for(k=0;k<t;k++) {
            cin >> str;
            vt.push_back(str);
            up = &head;
            for(i=0;i<str.size();i++) {
                int idx = str[i] - 'a';
                if(up->ck[idx] == false) {
                    up->ck[idx] = true;
                    up->n++;
                    trie ntrie;
                    up->ma[idx] = ntrie;
                }
                up = &up->ma[idx];
            }
            up->n++;
        }
        for(i=0;i<vt.size();i++) {
            sum++;
            up = &head.ma[vt[i][0]-'a'];
            for(j=1;j<vt[i].size();j++) {
                if(up->n != 1) sum++;
                up = &up->ma[vt[i][j]-'a'];
            }
        }
        cout << (double)sum/t << "\n";
    }
    return 0;
}