//11650 좌표 정렬하기 - C++17
//메모리 : 3568KB / 시간 : 132ms
//2024년 4월 22일 03:30:24

#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> ii;


int main() {
    int n, a, b;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    cin >> n;
    while(n--) {
        cin >> a >> b;
        pq.push({a, b});
    }
    while(!pq.empty()) {
        cout << pq.top().first << " " << pq.top().second << "\n";
        pq.pop();
    }
    return 0;
}