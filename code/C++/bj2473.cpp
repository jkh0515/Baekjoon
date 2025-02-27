//2473 세 용액 - C++17
//메모리 : 2156KB / 시간 : 24ms
//2024년 5월 22일 00:21:21

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long n, i, a = 0, b = 1, c = 2, d, p1, p2, p3, p4, t;
    cin >> n;
    vector<long> vt;
    for(i=0;i<n;i++) {
        cin >> t;
        vt.push_back(t);
    }
    sort(vt.begin(), vt.end());
    d = abs(vt[0] + vt[1] + vt[2]);
    for(i=1;i<n-1;i++) {
        p1 = 0, p2 = i, p3 = n - 1;
        while(p3 > i and p1 < i) {
            // cout << p1 << " " << p2 << " " << p3 << endl;
            p4 = vt[p1] + vt[p2] + vt[p3];
            if(abs(p4) == 0) {
                a = p1, b = p2, c = p3, d = 0;
                break;
            }
            if(abs(p4) < d) a = p1, b = p2, c = p3, d = abs(p4);
            if(p4 > 0) p3--;
            else p1++;
        }
        if(d == 0) break;
        // cout << endl;
    }
    cout << vt[a] << " " << vt[b] << " " << vt[c];
    return 0;
}