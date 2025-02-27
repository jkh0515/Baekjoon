//27652 AB - C++17
//메모리 : 4292KB / 시간 : 424ms
//2024년 5월 5일 21:21:43

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    map<string, int> am, bm;
    vector<string> av, bv;
    int n, i, j, ab[1000] = {0}, bb[1000] = {0};
    string how, what, str;
    cin >> n;
    while(n--) {
        cin >> how;
        int fd[1000][2] = {0}, ans = 0;
        if(how == "find") {
            cin >> str;
            for(i=1;i<str.size();i++) {
                string afstr = str.substr(0, i), bfstr = str.substr(i, str.size()-i);
                for(j=0;j<av.size();j++) {
                    if(ab[j] == 0 or av[j].size() < i) continue;
                    if(av[j].substr(0, i) == afstr) fd[i][0]++;
                }
                for(j=0;j<bv.size();j++) {
                    if(bb[j] == 0 or bv[j].size() < bfstr.size()) continue;
                    if(bv[j].substr(bv[j].size()-bfstr.size(), bfstr.size()) == bfstr) fd[i][1]++;
                }
                ans += fd[i][0] * fd[i][1];
                // cout << afstr << " " << bfstr << " " << fd[i][0] << " " << fd[i][1] << endl;
            }
            cout << ans << "\n";
            // cout << "A : ";
            // for(int i=0;i<av.size();i++)
            //     if(ab[i]) cout << av[i] << " ";
            // cout << endl << "B : ";
            // for(int i=0;i<bv.size();i++)
            //     if(bb[i]) cout << bv[i] << " ";
            // cout << endl;
        }
        else {
            cin >> what >> str;
            if(what == "A") {
                if(how == "add") {
                    av.push_back(str);
                    am[str] = av.size() - 1;
                    ab[av.size() - 1] = 1;
                }
                else ab[am[str]] = 0;
            }
            else {
                if(how == "add") {
                    bv.push_back(str);
                    bm[str] = bv.size() - 1;
                    bb[bv.size() - 1] = 1;
                }
                else bb[bm[str]] = 0;
            }
        }
    }
    return 0;
}