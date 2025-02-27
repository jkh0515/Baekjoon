//1655 가운데를 말해요 - C++17
//메모리 : 2792KB / 시간 : 28ms
//2024년 4월 10일 14:58:47

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, i, t;
    cin >> n;
    priority_queue<int> one;
    priority_queue<int, vector<int>, greater<int>> two;
    for(i=0;i<n;i++) {
        cin >> t;
        if(one.size() == two.size()) {
            two.push(t);
            one.push(two.top());
            two.pop();
        }
        else {
            one.push(t);
            two.push(one.top());
            one.pop();
        }
        cout << one.top() << "\n";
    }
    return 0;
}