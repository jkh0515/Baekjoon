//2243 사탕상자 - C++17
//메모리 : 21552KB / 시간 : 72ms
//2024년 5월 30일 00:08:50

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int tree[4000000], arr[1000001];

int update(int node, int start, int end, int idx, int diff) {
    if(start > idx or end < idx) return 0;
    tree[node] += diff;
    if(start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx, diff);
        update(node * 2 + 1, mid + 1, end, idx, diff);
    }
    return 0;
}

int cal(int node, int start, int end, int cnt) {
    if(start == end) {
        cout << start << "\n";
        arr[start]--;
        update(1, 1, 1000000, start, -1);
        return 0;
    }
    int mid = (start + end) / 2;
    if(tree[node * 2] >= cnt) return cal(node * 2, start, mid, cnt);
    else return cal(node * 2 + 1, mid + 1, end, cnt - tree[node * 2]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, a, b, c;
    cin >> n;
    while(n--) {
        cin >> a >> b;
        if(a == 1) cal(1, 1, 1000000, b);
        else {
            cin >> c;
            update(1, 1, 1000000, b, c);
        }
    }
    return 0;
}
