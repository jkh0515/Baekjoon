//2467 용액 - C++17
//메모리 : 2804KB / 시간 : 64ms
//2024년 5월 21일 22:06:02

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, i, a, b, c, p1, p2, p3, t;
    cin >> n;
    vector<int> vt;
    for(i=0;i<n;i++) {
        cin >> t;
        vt.push_back(t);
    }
    sort(vt.begin(), vt.end());
    // for(i=0;i<n;i++)
    //     cout << vt[i] << " ";
    a = 0, b = n-1, c = abs(vt[a] + vt[b]);
    p1 = 0, p2 = n-1;
    while(p2 > p1) {
        p3 = abs(vt[p1] + vt[p2]);
        if(p3 == 0) {
            a = p1, b = p2;
            break;
        }
        if(p3 < c) c = p3, a = p1, b = p2;
        if(vt[p1] + vt[p2] > 0) p2--;
        else p1++;
    }
    cout << vt[a] << " " << vt[b];
    return 0;
}