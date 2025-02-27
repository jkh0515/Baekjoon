//1202 보석 도둑 - C++17
//메모리 : 11272KB / 시간 : 500ms
//2024년 4월 10일 00:57:49

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ii;

int main() {
    int n, k, a, b, c = 0, d = 0, i, arr[300001];
    long long ans = 0;
    cin >> n >> k;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    priority_queue<int> li;
    for(i=0;i<n;i++) {
        cin >> a >> b;
        pq.push({a, b});
    }
    for(i=0;i<k;i++)
        cin >> arr[i];
    sort(arr, arr+k);
    while(!pq.empty()) {
        int v = pq.top().first;
        int m = pq.top().second;
        pq.pop();
        // cout << v << " " << m << " " << arr[c] << endl;
        while(v > arr[c] and c <= k) c++;
        if(c == k + 1) break;
        for(i=d;i<c;i++) {
            if(li.empty()) break;
            ans += (long long)li.top();
            li.pop();
        }
        d = c;
        li.push(m);
    }
    for(i=d;i<k;i++) {
        if(li.empty()) break;
        ans += (long long)li.top();
        li.pop();
    }
    cout << ans;
    return 0;
}