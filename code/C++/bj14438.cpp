//14438 수열과 쿼리 17 - C++17
//메모리 : 5928KB / 시간 : 68ms
//2024년 4월 17일 01:27:24

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n, q, i, a, b, c, d, arr[100001], st[400004];

ll init(int idx, int start, int end) {
    if(start == end) return st[idx] = arr[start];
    int mid = (start + end) / 2;
    return st[idx] = min(init(idx * 2, start, mid), init(idx * 2 + 1, mid + 1, end));
}

ll update(int idx, int start, int end, int node) {
    if(start > node or end < node) return st[idx];
    if(start == end) return st[idx] = arr[start];
    int mid = (start + end) / 2;
    return st[idx] = min(update(idx * 2, start, mid, node), update(idx * 2 + 1, mid + 1, end, node));
}

ll stmin(int idx, int start, int end, int left, int right) {
    if(left > end or right < start) return 1e9;
    if(left <= start and right >= end) return st[idx];
    if(start == end) return 1e9;
    int mid = (start + end) / 2;
    return min(stmin(idx * 2, start, mid, left, right), stmin(idx * 2 + 1, mid + 1, end, left, right));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(i=1;i<=n;i++)
        cin >> arr[i];
    init(1, 1, n);
    cin >> q;
    while(q--) {
        cin >> a >> b >> c;
        if(a == 1) {
            arr[b] = c;
            update(1, 1, n, b);
            // for(i=1;i<=n*4;i++)
            //     cout << st[i] << " ";
            // cout << endl;
        }
        else cout << stmin(1, 1, n, b, c) << "\n";
    }
    // for(i=1;i<n*4;i++)
    //     cout << st[i] << " ";
    // cout << endl;
    return 0;
}