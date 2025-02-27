//2504 괄호의 값 - C++17
//메모리 : 2024KB / 시간 : 0ms
//2024년 2월 12일 03:08:47

#include <iostream>
#include <vector>
using namespace std;
#define m 1e9

int main() {
    string str;
    int i, ans = 0, a[100];
    a[40] = m, a[41] = m+2, a[91] = m+1, a[93] = m+3; 
    vector<int> vt(1, 0);
    cin >> str;
    for(i=1;i<=str.size();i++) {
        vt.push_back(a[str[i-1]]);
        if(vt.back() >= m + 2) {
            int b = vt.back(), t = 0;
            vt.pop_back();
            while(vt.size()) {
                if(vt.back() < m and vt.back() != 0) {
                    t += vt.back();
                    vt.pop_back();
                    continue;
                }
                if(vt.back() == b - 2) {
                    if(t == 0) t++;
                    vt.pop_back();
                    vt.push_back(t*(b-m));
                    break;
                }
                else {
                    cout << "0";
                    return 0;
                }
            }
        }
    }
    for(i=0;i<vt.size();i++) {
        if(vt[i] >= m) {
            cout << "0";
            return 0;
        }
        ans += vt[i];
    }
    cout << ans;
    return 0;
}
