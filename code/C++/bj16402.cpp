//16402 제국 - C++17
//메모리 : 8780KB / 시간 : 200ms
//2024년 5월 2일 00:46:52

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

class kingdom {
    public :
    bool state;
    string up;
    vector<string> down;
    kingdom() {
        state = 1;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, i, w, t, ans = 0;
    string a, b, c, d, e, f;
    map<string, kingdom> ma;
    priority_queue<string, vector<string>, greater<string>> pq;
    vector<string> vt;
    cin >> n >> m;
    for(i=0;i<n;i++) {
        cin >> a >> a >> a;
        kingdom newK;
        pq.push(a);
        ma[a] = newK;
    }
    for(i=0;i<m;i++) {
        cin >> a >> a >> a >> b >> b;
        a = a.substr(0, a.size()-8);
        w = b[b.size()-1] - '0';
        b = b.substr(0, b.size()-2);
        if(ma[a].state == 0) {
            c = a;
            a = ma[a].up;
            t = 2;
        }
        if(ma[b].state == 0) {
            d = b;
            b = ma[b].up;
            t = 1;
        }
        if(a == b) {
            if(w == t) continue;
            if(t == 1) e = d, f = b;
            else e = c, f = a;
        }
        else if(w == 1) e = a, f = b;
        else e = b, f = a;
        ma[e].state = 1;
        ma[f].state = 0;
        ma[f].up = e;
        while(ma[f].down.size() > 0) {
            if(ma[f].down.back() == e) {
                ma[f].down.pop_back();
                continue;
            }
            ma[e].down.push_back(ma[f].down.back());
            ma[ma[f].down.back()].up = e;
            ma[f].down.pop_back();
        }
        ma[e].down.push_back(f);
        // cout << f << " -> " << e << " : " << ma[f].down.size() << " / ";
        // for(int k=0;k<ma[e].down.size();k++) cout << ma[e].down[k] << " ";
        // cout << endl;
    }
    while(!pq.empty()) {
        if(ma[pq.top()].state == 1) {
            ans++;
            vt.push_back(pq.top());
        }
        pq.pop();
    }
    cout << ans << "\n";
    for(i=0;i<ans;i++)
        cout << "Kingdom of " << vt[i] << "\n";
    return 0;
}