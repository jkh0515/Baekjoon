//2164 카드2 - C++17
//메모리 : 4040KB / 시간 : 4ms
//2024년 4월 30일 00:53:44

#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int n, i;
    cin >> n;
    for(i=1;i<=n;i++)
        q.push(i);
    while(q.size() != 1) {
        q.pop();
        n = q.front();
        q.pop();
        q.push(n);
    }
    cout << q.front();
    return 0;
}