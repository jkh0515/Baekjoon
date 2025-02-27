//1043 거짓말 - C++17
//메모리 : 2024KB / 시간 : 0ms
//2024년 1월 28일 02:51:40

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool bpl[51], bpt[51];
vector<int> vtpl[51], vtpt[51];

int cal(int pl) {
    for(int i=0;i<vtpl[pl].size();i++) {
        if(bpt[vtpl[pl][i]] == 1) continue;
        for(int j=0;j<vtpt[vtpl[pl][i]].size();j++) {
            if(bpl[vtpt[vtpl[pl][i]][j]] == 1) continue;
            bpl[vtpt[vtpl[pl][i]][j]] = 1;
            cal(vtpt[vtpl[pl][i]][j]);
        }
        bpt[vtpl[pl][i]] = 1;
    }
    return 0;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    int n, k, t, ck, i, j, pl, answer = 0;
    vector<int> tg;
    cin >> n >> k >> i;
    while(i--) {
        cin >> pl;
        tg.push_back(pl);
    }
    for(i=1;i<=k;i++) {
        cin >> t;
        while(t--) {
            cin >> pl;
            vtpt[i].push_back(pl);
            vtpl[pl].push_back(i);
        }
    }
    for(i=0;i<tg.size();i++)
        cal(tg[i]);
    for(i=1;i<=k;i++)
        answer += bpt[i];
    cout << k-answer;
    return 0;
}