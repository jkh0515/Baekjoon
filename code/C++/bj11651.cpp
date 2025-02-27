//11651 좌표 정렬하기 2 - C++17
//메모리 : 3568KB / 시간 : 124ms
//2024년 4월 30일 00:45:45

#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

int main() {
    int n, a, b;
    cin >> n;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    while(n--) {
        cin >> a >> b;
        pq.push({b, a});
    }
    while(!pq.empty()) {
        cout << pq.top().second << " " << pq.top().first << "\n";
        pq.pop();
    }
    return 0;
}