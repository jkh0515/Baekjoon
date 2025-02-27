//14428 수열과 쿼리 16 - C++17
//메모리 : 5536KB / 시간 : 80ms
//2024년 4월 18일 21:26:52

#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int n, i, asize, a, b, c, arr[100002];
ii st[400004];

ii imin(ii a, ii b) {
    if(arr[a.first] < arr[b.first]) return a;
    if(arr[a.first] > arr[b.first]) return b;
    if(a.first < b.first) return a;
    else return b;
}

ii init(int idx, int start, int end) {
    if(start == end) return st[idx] = {start, idx};
    int mid = (start + end) / 2;
    return st[idx] = imin(init(idx*2, start, mid), init(idx*2+1, mid+1, end));
}

ii update(int idx, int start, int end, int target) {
    if(start > target or end < target) return st[idx];
    if(start == end) return st[idx] = {target, idx};
    int mid = (start + end) / 2;
    return st[idx] = imin(update(idx*2, start, mid, target), update(idx*2+1, mid+1, end, target));
}

ii fimin(int idx, int start, int end, int left, int right) {
    if(start > right or end < left) return {100001, idx};
    if(left <= start and right >= end) return st[idx];
    if(start == end) return {100001, idx};
    int mid = (start + end) / 2;
    return imin(fimin(idx*2, start, mid, left, right), fimin(idx*2+1, mid+1, end, left, right));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(i=1;i<=n;i++)
        cin >> arr[i];
    init(1, 1, n);
    cin >> asize;
    arr[100001] = 1e9;
    // for(i=1;i<=n*4;i++)
    //     cout << arr[st[i].first] << " ";
    // cout << endl;
    while(asize--) {
        cin >> a >> b >> c;
        if(a == 1) {
            arr[b] = c;
            update(1, 1, n, b);
        }
        else {
            cout << fimin(1, 1, n, b, c).first << "\n";
        }
    }
    return 0;
}