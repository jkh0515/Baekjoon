//7662 이중 우선순위 큐 - C++17
//메모리 : 57128KB / 시간 : 1616ms
//2024년 4월 17일 23:21:23

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t, q, a, size;
    string str;
    cin >> t;
    while(t--) {
        size = 0;
        cin >> q;
        priority_queue<int> bpq;
        priority_queue<int, vector<int>, greater<int>> spq;
        map<int, int> ma;
        while(q--) {
            cin >> str >> a;
            if(str == "I") {
                size++;
                ma[a]++;
                bpq.push(a);
                spq.push(a);
            }
            else if(size > 0){
                size--;
                if(size == 0) {
                    ma.clear();
                    bpq = priority_queue<int>();
                    spq = priority_queue<int, vector<int>, greater<int>>();
                }
                else {
                    if(a == 1) {
                        ma[bpq.top()]--;
                        bpq.pop();
                    }
                    else {
                        ma[spq.top()]--;
                        spq.pop();
                    }
                    while(!spq.empty() and ma[spq.top()] == 0) spq.pop();
                    while(!bpq.empty() and ma[bpq.top()] == 0) bpq.pop();
                }
            }
        }
        if(size == 0) cout << "EMPTY\n";
        else {
            while(!spq.empty() and ma[spq.top()] == 0) spq.pop();
            while(!bpq.empty() and ma[bpq.top()] == 0) bpq.pop();
            cout << bpq.top() << " " << spq.top() << "\n";
        }
    }
    return 0;
}