//17270 연예인은 힘들어 - C++17
//메모리 : 2024KB / 시간 : 0ms
//2024년 2월 19일 02:32:51

#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int v, m, a, b, c, j, s, i, ans = -1e9, n, mm = -1e9;
    cin >> v >> m;
    vector<pair<int, int>> vt[101];
    priority_queue<pair<int, int>> pq;
    int arr1[101], arr2[101];
    fill(&arr1[0], &arr1[v+1], -1e9);
    fill(&arr2[0], &arr2[v+1], -1e9);
    for(i=0;i<m;i++) {
        cin >> a >> b >> c;
        vt[a].push_back({c, b});
        vt[b].push_back({c, a});
    }
    cin >> j >> s;
    pq.push({0, j});
    arr1[j] = 0;
    while(!pq.empty()) {
        int w = pq.top().first;
        int r = pq.top().second;
        pq.pop();
        if(arr1[r] < w) continue;
        for(i=0;i<vt[r].size();i++) {
            int tw = w - vt[r][i].first;
            int tr = vt[r][i].second;
            if(arr1[tr] < tw) {
                pq.push({tw, tr});
                arr1[tr] = tw;
            }
        }
    }
    pq.push({0, s});
    arr2[s] = 0;
    while(!pq.empty()) {
        int w = pq.top().first;
        int r = pq.top().second;
        pq.pop();
        if(arr2[r] < w) continue;
        for(i=0;i<vt[r].size();i++) {
            int tw = w - vt[r][i].first;
            int tr = vt[r][i].second;
            if(arr2[tr] < tw) {
                pq.push({tw, tr});
                arr2[tr] = tw;
            }
        }
    }
    // for(i=1;i<=v;i++) {
    //     cout << arr1[i] << "  " << arr2[i] << "  " << arr1[i]+arr2[i] << endl;
    // }
    for(i=1;i<=v;i++) {
        if(i == s or i == j) continue;
        mm = max(mm, arr1[i]+arr2[i]);
        if(arr1[i] < arr2[i]) continue;
        if(ans > arr1[i]+arr2[i]) continue;
        if(ans < arr1[i]+arr2[i]) {
            ans = arr1[i]+arr2[i];
            n = i;
        }
        if(ans == arr1[i]+arr2[i] and arr1[i] > arr1[n])
            n = i;
    }
    if(ans == -1e9 or ans != mm) cout << "-1";
    else cout << n;
    return 0;
}