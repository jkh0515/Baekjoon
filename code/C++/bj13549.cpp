//13549 숨바꼭질 3 - C++17
//메모리 : 2680KB / 시간 : 8ms
//2024년 2월 14일 00:11:50

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int a, b;
    int arr[100001] = {0};
    cin >> a >> b;
    fill(&arr[0], &arr[100001]+1, -1e9);
    priority_queue<pair<int, int>> pq;
    pq.push({0, a});
    arr[a] = 0;
    while(!pq.empty()) {
        int w = pq.top().first;
        int n = pq.top().second;
        pq.pop();
        if(n == b) break;
        if(n < 0 or n > 100000) continue;
        if(arr[n] < w) continue;
        if(n <= 50000 and arr[n*2] < w) {
            arr[n*2] = w;
            pq.push({w, n*2});
        }
        if(arr[n+1] < w - 1) {
            arr[n+1] = w - 1;
            pq.push({w-1, n+1});
        }
        if(arr[n-1] < w - 1) {
            arr[n-1] = w - 1;
            pq.push({w-1, n-1});
        }
    }
    cout << arr[b] * -1;
    return 0;
}