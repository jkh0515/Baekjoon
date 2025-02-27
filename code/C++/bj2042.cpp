//2042 구간 합 구하기 - C++17
//메모리 : 41084KB / 시간 : 220ms
//2024년 4월 14일 22:16:48

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n, m, k, i, a, b, c, arr[1000001], st[4000004];

ll init(int idx, int start, int end) {
    if(start == end) return st[idx] = arr[start];
    int mid = (start + end) / 2;
    return st[idx] = init(idx * 2, start, mid) + init(idx * 2 + 1, mid + 1, end);
}

void update(int idx, int start, int end, int node, ll diff) {
    if(start > node or end < node) return;
    st[idx] += diff;
    if(start == end) return;
    int mid = (start + end) / 2;
    update(idx * 2, start, mid, node, diff);
    update(idx * 2 + 1, mid + 1, end, node, diff);
    return;
}

ll sum(int idx, int start, int end, int left, int right) {
    if(start > right or end < left) return 0;
    if(end <= right and start >= left) return st[idx];
    int mid = (start + end) / 2;
    return sum(idx * 2, start, mid, left, right) + sum(idx * 2 + 1, mid + 1, end, left, right);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for(i=1;i<=n;i++)
        cin >> arr[i];
    init(1, 1, n);
    for(i=0;i<m+k;i++) {
        cin >> a >> b >> c;
        if(a == 2) cout << sum(1, 1, n, b, c) << "\n";
        else {
            update(1, 1, n, b, c - arr[b]);
            arr[b] = c;
        }
    }
    return 0;
}