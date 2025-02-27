//14725 개미굴 - C++17
//메모리 : 3228KB / 시간 : 4ms
//2024년 4월 13일 00:55:37

#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

typedef struct mp {
    priority_queue<string, vector<string>, greater<string>> pq;
    map<string, mp> ma;
} mp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    mp head, *now;
    vector<pair<mp, int>> vt;
    string str;
    int n, k, i;
    cin >> n;
    while(n--) {
        cin >> k;
        now = &head;
        while(k--) {
            cin >> str;
            if(now->ma.find(str) == now->ma.end()) {
                mp nmp;
                now->pq.push(str);
                now->ma[str] = nmp;
            }
            now = &now->ma[str];
        }
    }
    vt.push_back({head, 0});
    while(vt.size() != 0) {
        if(vt.back().first.pq.size() == 0) {
            vt.pop_back();
            continue;
        }
        for(i=0;i<vt.back().second;i++) cout << "--";
        cout << vt.back().first.pq.top() << "\n";
        str = vt.back().first.pq.top();
        vt.back().first.pq.pop();
        vt.push_back({vt.back().first.ma[str], vt.back().second + 1});
    }
    return 0;
}