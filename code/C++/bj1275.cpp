//1275 커피숍2 - C++17
//메모리 : 5928KB / 시간 : 112ms
//2024년 4월 14일 15:20:32

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n, q, i, x, y, a, b, arr[100001], st[400004];

ll init(int idx, int start, int end) {
    if(start == end) return st[idx] = arr[start];
    int mid = (start + end) / 2;
    return st[idx] = init(idx * 2, start, mid) + init(idx * 2 + 1, mid + 1, end);
}

void update(int idx, int start, int end, int node, ll diff) {
    if(start > node or end < node) return;
    st[idx] += diff;
    if(start != end) {
        int mid = (start + end) / 2;
        update(idx * 2, start, mid, node, diff);
        update(idx * 2 + 1, mid + 1, end, node, diff);
    }
    return;
}

ll sum(int idx, int start, int end, int left, int right) {
    if(right < start or left > end) return 0;
    if(left <= start and right >= end) return st[idx];
    int mid = (start + end) / 2;
    return sum(idx * 2, start, mid, left, right) + sum(idx * 2 + 1, mid + 1, end, left, right);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for(i=1;i<=n;i++)
        cin >> arr[i];
    init(1, 1, n);
    while(q--) {
        cin >> x >> y >> a >> b;
        cout << sum(1, 1, n, min(x, y), max(x, y)) << "\n";
        update(1, 1, n, a, b - arr[a]);
        arr[a] = b;
    }
    // for(i=1;i<n*4;i++)
    //     cout << st[i] << " ";
    // cout << endl;
    return 0;
}