//11286 절댓값 힙 - C++17
//메모리 : 2916KB / 시간 : 16ms
//2024년 5월 10일 21:48:52

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

typedef pair<int, int> ii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    int n, t;
    cin >> n;
    while(n--) {
        cin >> t;
        if(t == 0) {
            if(pq.empty()) cout << "0\n";
            else {
                cout << pq.top().second << "\n";
                pq.pop();
            }
        }
        else pq.push({abs(t), t});
    }
    return 0;
}