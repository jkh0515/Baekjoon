//1884 고속도로 - C++17
//메모리 : 15244KB / 시간 : 180ms
//2024년 2월 11일 01:57:36

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int k, n, r, s, d, l, t, i, ans = -1e9;
    cin >> k >> n >> r;
    int arr[101][10001] = {0};
    fill(&arr[0][0], &arr[n][k]+1, -1e9);
    vector<pair<int, pair<int, int>>> road[101];
    priority_queue<pair<int, pair<int, int>>> pq;
    while(r--) {
        cin >> s >> d >> l >> t;
        road[s].push_back({d, {l, t}});
    }
    pq.push({0, {0, 1}});
    for(i=0;i<=k;i++)
        arr[1][i] = 0;
    while(!pq.empty()) {
        int len = pq.top().first;
        int pay = pq.top().second.first;
        int city = pq.top().second.second;
        pq.pop();
        if(arr[city][pay] < len) continue;
        for(i=0;i<road[city].size();i++) {
            int tlen = len - road[city][i].second.first;
            int tpay = pay + road[city][i].second.second;
            int tcity = road[city][i].first;
            if(tpay > k) continue;
            if(arr[tcity][tpay] < tlen) {
                arr[tcity][tpay] = tlen;
                pq.push({tlen, {tpay, tcity}});
            }
        }
    }
    for(i=0;i<=k;i++) 
        ans = max(ans, arr[n][i]);
    if(ans == -1e9) cout << "-1";
    else cout << ans * -1;
        // cout << arr[n][i] << " ";
    return 0;
}