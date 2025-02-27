//10868 최솟값 - C++17
//메모리 : 3972KB / 시간 : 80ms
//2024년 4월 15일 20:58:14

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

int arr[100001], st[400004], n, m, a, b, i;

ll init(int idx, int start, int end) {
    if(start == end) return st[idx] = arr[start];
    int mid = (start + end) / 2;
    return st[idx] = min(init(idx * 2, start, mid), init(idx * 2 + 1, mid + 1, end));
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
    cin >> n >> m;
    for(i=1;i<=n;i++)
        cin >> arr[i];
    init(1, 1, n);
    while(m--) {
        cin >> a >> b;
        cout << stmin(1, 1, n, a, b) << "\n";
    }
    return 0;
}