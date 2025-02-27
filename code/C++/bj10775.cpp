//10775 공항 - C++17
//메모리 : 2800KB / 시간 : 524ms
//2024년 4월 13일 14:03:24

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int g, p, t, i;
    cin >> g >> p;
    vector<int> vt;
    for(i=1;i<=g;i++)
        vt.push_back(i);
    for(i=0;i<p;i++) {
        cin >> t;
        int idx = lower_bound(vt.begin(), vt.end(), t) - vt.begin();
        if(idx < vt.size() and vt[idx] == t) vt.erase(vt.begin() + idx);
        else {
            idx = max(idx - 1, 0);
            if(idx >= vt.size() or vt[idx] > t) break;
            vt.erase(vt.begin() + idx);
        }
        // for(int j=0;j<vt.size();j++)
        //     cout << vt[j] << " ";
        // cout << endl;
    }
    cout << g - vt.size();
    return 0;
}