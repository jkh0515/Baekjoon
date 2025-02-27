//10866 덱 - C++17
//메모리 : 2024KB / 시간 : 4ms
//2024년 4월 23일 03:52:45

#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, t;
    string str;
    deque<int> dq;
    cin >> n;
    while(n--) {
        cin >> str;
        if(str == "front") {
            if(dq.empty()) cout << "-1\n";
            else cout << dq.front() << "\n";
        }
        else if(str == "back") {
            if(dq.empty()) cout << "-1\n";
            else cout << dq.back() << "\n";
        }
        else if(str == "push_front") {
            cin >> t;
            dq.push_front(t);
        }
        else if(str == "push_back") {
            cin >> t;
            dq.push_back(t);
        }
        else if(str == "pop_back") {
            if(dq.empty()) cout << "-1\n";
            else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        else if(str == "pop_front") {
            if(dq.empty()) cout << "-1\n";
            else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        else if(str == "size") cout << dq.size() << "\n";
        else if(str == "empty") cout << dq.empty() << "\n";
    }
    return 0;
}