//2263 트리의 순회 - C++17
//메모리 : 7236KB / 시간 : 32ms
//2024년 5월 24일 01:58:53

#include <iostream>
#include <algorithm>
using namespace std;

int idx[100000], in[100000], post[100000];

void cal(int istart, int iend, int pstart, int pend) {
    if(istart > iend or pstart > pend) return;
    int ridx = idx[post[pend]];
    int psize = ridx - istart;
    cout << in[ridx] << " ";
    cal(istart, ridx-1, pstart, pstart+psize-1);
    cal(ridx+1, iend, pstart+psize, pend-1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, i;
    cin >> n;
    for(i=0;i<n;i++) {
        cin >> in[i];
        idx[in[i]] = i;
    }
    for(i=0;i<n;i++)
        cin >> post[i];
    cal(0, n-1, 0, n-1);
    return 0;
}