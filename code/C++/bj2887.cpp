//2887 행성 터널 - C++17
//메모리 : 20952KB / 시간 : 144ms
//2024년 5월 27일 23:48:47

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, i, x, y, z, t, arr[100001];
    long long ans = 0;
    vector<int> vt[100001];
    vector<ii> xvt, yvt, zvt;
    cin >> n;
    for(i=1;i<=n;i++) {
        arr[i] = i;
        vt[i].push_back(i);
        cin >> x >> y >> z;
        xvt.push_back({x, i});
        yvt.push_back({y, i});
        zvt.push_back({z, i});
    }
    sort(xvt.begin(), xvt.end());
    sort(yvt.begin(), yvt.end());
    sort(zvt.begin(), zvt.end());
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    for(i=0;i<n-1;i++) {
        if(vt[1].size() == n) break;
        pq.push({xvt[i+1].first - xvt[i].first, {xvt[i].second, xvt[i+1].second}});
        pq.push({yvt[i+1].first - yvt[i].first, {yvt[i].second, yvt[i+1].second}});
        pq.push({zvt[i+1].first - zvt[i].first, {zvt[i].second, zvt[i+1].second}});
    }
    while(!pq.empty()) {
        if(vt[1].size() == n) break;
        int w = pq.top().first;
        int a = arr[pq.top().second.first];
        int b = arr[pq.top().second.second];
        // cout << w << " / " << a << ": " << arr[a] << " / " << b << ": " << arr[b] << endl;
        pq.pop();
        if(a != b) {
            t = min(a, b), b = max(a, b), a = t;
            while(vt[b].size() > 0) {
                t = vt[b].back();
                vt[a].push_back(t);
                arr[t] = a;
                vt[b].pop_back();
            }
            ans += w;
            // cout << w << " ";
        }   
    }
    // cout << endl;
    // for(i=0;i<n;i++) {
    //     cout << vt[1][i] << " ";
    // }
    // cout << endl;
    cout << ans;
    return 0;
}