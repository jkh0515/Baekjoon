//2798 블랙잭 - C++17
//메모리 : 4740KB / 시간 : 4ms
//2024년 5월 3일 23:36:40

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, carr[3] = {0, }, arr[300001];
priority_queue<int> pq;

void combination(int depth, int next, int n){
    if(depth == 3){
        pq.push(arr[carr[0]-1] + arr[carr[1]-1] + arr[carr[2]-1]);
        return;
    }
    for(int i=next;i<=n;i++){
        carr[depth] = i;
        combination(depth+1, i+1, n);
    }
}

int main() {
    int m, i;
    cin >> n >> m;
    for(i=0;i<n;i++)
        cin >> arr[i];
    combination(0, 1, n);
    while(!pq.empty()) {
        if(pq.top() > m) pq.pop();
        else break;
    }
    cout << pq.top();
    return 0;
}