//2357 최솟값과 최댓값 - C++17
//메모리 : 5536KB / 시간 : 132ms
//2024년 4월 15일 21:11:13

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

int arr[100001], minst[400004], maxst[400004], n, m, a, b, i;

ll init1(int idx, int start, int end) {
    if(start == end) return minst[idx] = arr[start];
    int mid = (start + end) / 2;
    return minst[idx] = min(init1(idx * 2, start, mid), init1(idx * 2 + 1, mid + 1, end));
}

ll init2(int idx, int start, int end) {
    if(start == end) return maxst[idx] = arr[start];
    int mid = (start + end) / 2;
    return maxst[idx] = max(init2(idx * 2, start, mid), init2(idx * 2 + 1, mid + 1, end));
}

ll stmin(int idx, int start, int end, int left, int right) {
    if(left > end or right < start) return 1e9;
    if(left <= start and right >= end) return minst[idx];
    if(start == end) return 1e9;
    int mid = (start + end) / 2;
    return min(stmin(idx * 2, start, mid, left, right), stmin(idx * 2 + 1, mid + 1, end, left, right));
}

ll stmax(int idx, int start, int end, int left, int right) {
    if(left > end or right < start) return -1;
    if(left <= start and right >= end) return maxst[idx];
    if(start == end) return -1;
    int mid = (start + end) / 2;
    return max(stmax(idx * 2, start, mid, left, right), stmax(idx * 2 + 1, mid + 1, end, left, right));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(i=1;i<=n;i++)
        cin >> arr[i];
    init1(1, 1, n);
    init2(1, 1, n);
    while(m--) {
        cin >> a >> b;
        cout << stmin(1, 1, n, a, b) << " " << stmax(1, 1, n, a, b) << "\n";
    }
    return 0;
}