//1927 최소 힙 - C++17
//메모리 : 2916KB / 시간 : 12ms
//2024년 5월 10일 17:03:22

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    priority_queue<int, vector<int>, greater<int>> pq;
    int n, t;
    cin >> n;
    while(n--) {
        cin >> t;
        if(t == 0) {
            if(pq.empty()) cout << "0\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else pq.push(t);
    }
    return 0;
}