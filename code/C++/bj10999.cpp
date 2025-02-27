//10999 구간 합 구하기 2 - C++17
//메모리 : 72332KB / 시간 : 180ms
//2024년 6월 29일 02:37:05

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
ll arr[1000001], tr[4000001], lazy[4000001];

void init(int node, int start, int end) {
    if(start == end) tr[node] = arr[start];
    else {
        int mid = (start + end) / 2;
        init(node * 2, start, mid);
        init(node * 2 + 1, mid + 1, end);
        tr[node] = tr[node * 2] + tr[node * 2 + 1];
    }
}

ll sum(int node, int start, int end, int lhs, int rhs) {
    tr[node] += (end - start + 1) * lazy[node];
    if(start != end) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
    if(end < lhs or rhs < start) return 0;
    if(lhs <= start and end <= rhs) return tr[node];
    ll mid = (start + end) / 2;
    return sum(node * 2, start, mid, lhs, rhs) + sum(node * 2 + 1, mid + 1, end, lhs, rhs);
}

void add(int node, int start, int end, int lhs, int rhs, ll weight) {
    tr[node] += (end - start + 1) * lazy[node];
    if(start != end) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
    if(end < lhs or rhs < start) return;
    if(lhs <= start and end <= rhs) {
        tr[node] += (end - start + 1) * weight;
        if(start != end) {
            lazy[node * 2] += weight;
            lazy[node * 2 + 1] += weight;
            
        }
        return;
    }
    int mid = (start + end) / 2;
    add(node * 2, start, mid, lhs, rhs, weight);
    add(node * 2 + 1, mid + 1, end, lhs, rhs, weight);
    tr[node] = tr[node * 2] + tr[node * 2 + 1];
    return;
}

void ch(int n) {
    int i;
    cout << endl;
    for(i=0;i<n*4;i++) cout << tr[i] << " ";
    cout << endl;
    for(i=0;i<n*4;i++) cout << lazy[i] << " ";
    cout << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll i, n, m, k, a, b, c, d;
    cin >> n >> m >> k;
    for(i=1;i<=n;i++)
        cin >> arr[i];
    init(1, 1, n);
    for(i=1;i<=m+k;i++) {
        cin >> a >> b >> c;
        if(a == 1) {
            cin >> d;
            add(1, 1, n, b, c, d);
        }
        else cout << sum(1, 1, n, b, c) << "\n"; 
        // ch(n);
    }
    return 0;
}