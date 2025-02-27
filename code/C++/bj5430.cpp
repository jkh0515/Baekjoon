//5430 AC - C++17
//메모리 : 3116KB / 시간 : 52ms
//2024년 5월 10일 01:42:25

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t, i, n, d;
    string str, mstr, num = "";
    cin >> t;
    while(t--) {
        num = "";
        cin >> str >> n >> mstr;
        deque<int> dq;
        d = 0, n = 0;
        for(i=1;i<mstr.size()-1;i++) {
            if(mstr[i] == ',') {
                dq.push_back(stoi(num));
                num = "";
            }
            else num += mstr[i];
        }
        if(num != "") dq.push_back(stoi(num));
        for(i=0;i<str.size();i++) {
            if(str[i] == 'R') d = (d+1)%2;
            else {
                if(dq.empty()) {
                    cout << "error\n";
                    n = -1;
                    break;
                }
                if(d == 0) dq.pop_front();
                else dq.pop_back();
            }
        }
        if(n != -1) {
            if(dq.size() == 0) cout << "[]\n";
            else if(d == 0) {
                cout << "[";
                for(i=0;i<dq.size()-1;i++)
                    cout << dq[i] << ",";
                cout << dq.back() << "]\n";
            }
            else {
                cout << "[";
                for(i=dq.size()-1;i>0;i--)
                    cout << dq[i] << ",";
                cout << dq.front() << "]\n";
            }
        }
    }
    return 0;
}