//9009 피보나치 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 8월 1일 23:59:08

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int i, j, n, t, m = 0;
    cin >> n;
    vector<int> vt, pb;
    pb.push_back(0);
    pb.push_back(1);
    for(i=0;i<n;i++) {
        cin >> t;
        m = max(m, t);
        vt.push_back(t);
    }
    while(pb.back() < m)
        pb.push_back(pb[pb.size()-1] + pb[pb.size()-2]);
    for(i=0;i<n;i++) {
        vector<int> ans;
        for(j=pb.size()-1;vt[i]>0;j--) {
            if(vt[i] >= pb[j]) {
                ans.push_back(pb[j]);
                vt[i] -= pb[j];
            }
        }
        for(j=ans.size()-1;j>=0;j--)
            cout << ans[j] << " ";
        cout << "\n";
    }
    return 0;
}