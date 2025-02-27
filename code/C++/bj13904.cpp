//13904 과제 - C++17
//메모리 : 2156KB / 시간 : 0ms
//2024년 4월 8일 20:42:29

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, i, d, w, ans = 0, arr[1001] = {0};
    cin >> n;
    priority_queue<pair<int, int>> pq;
    for(i=0;i<n;i++) {
        cin >> d >> w;
        pq.push({d, w});
    }
    while(!pq.empty()) {
        int td = pq.top().first;
        int tw = pq.top().second;
        pq.pop();
        while(td > 0) {
            if(arr[td] == 0) {
                arr[td] = tw;
                break;
            }
            if(arr[td] < tw) {
                int t = arr[td];
                arr[td] = tw;
                tw = t;
            }
            td--;
        }
    }
    for(i=1;i<=1000;i++) {
        // cout << i << " " << arr[i] << endl;
        ans += arr[i];
    }
    cout << ans;
}