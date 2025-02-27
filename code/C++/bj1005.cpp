//1005 ACM Craft - C++17
//메모리 : 2684KB / 시간 : 556ms
//2024년 1월 25일 21:11:46

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t, n, k, i, j, a, b, w;
    cin >> t;
    for(i=0;i<t;i++) {
        int darr[1001] = {0}, arr[1001] = {0}, entry[1001] = {0};
        vector<int> graph[1001];
        queue<int> q;
        cin >> n >> k;
        for(j=1;j<=n;j++)
            cin >> darr[j];
        for(j=0;j<k;j++) {
            cin >> a >> b;
            entry[b]++;
            graph[a].push_back(b);
        }
        cin >> w;
        for(j=1;j<=n;j++) {
            if(entry[j] == 0) {
                q.push(j);
                arr[j] = darr[j];
            }
        }
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            for(j=0;j<graph[top].size();j++) {
                int gj = graph[top][j];
                arr[gj] = max(arr[gj], darr[gj] + arr[top]);
                entry[gj]--;
                if(entry[gj] == 0)
                    q.push(gj);
            }
        }
        cout << arr[w] << "\n";
    }
    return 0;
}