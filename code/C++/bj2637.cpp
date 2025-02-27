//2637 장난감 조립 - C++17
//메모리 : 2024KB / 시간 : 0ms
//2024년 3월 12일 22:27:55

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m, i, j, a, b, c;
    vector<pair<int, int>> vt[101];
    int arr[101] = {0}, ck[101] = {0};
    priority_queue<int> q;
    cin >> n >> m;
    for(i=0;i<m;i++) {
        cin >> a >> b >> c;
        vt[a].push_back({b, c});
    }
    arr[n]++;
    q.push(n);
    while(!q.empty()) {
        int t = q.top();
        q.pop();
        if(vt[t].size() == 0 or arr[t] == 0) continue;
        // cout << t << " -> " << vt[t][0].second << " " << vt[t].size() << " : ";
        for(i=0;i<vt[t].size();i++) {
            // if(q.top() < vt[t][i].first)
            q.push(vt[t][i].first);
            arr[vt[t][i].first] += vt[t][i].second * arr[t];
        }
        arr[t] = 0;
        // for(i=1;i<=100;i++) {
        //     if(arr[i] == 0) continue;
        //     cout << i << " " << arr[i] << "  ";
        // }
        // cout << endl;  
    }
    for(i=1;i<=100;i++) {
        if(arr[i] == 0) continue;
        cout << i << " " << arr[i] << endl;
    }
    cout << endl;  
    return 0;
}