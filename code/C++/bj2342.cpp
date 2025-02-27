//2342 Dance Dance Revolution - C++17
//메모리 : 12572KB / 시간 : 92ms
//2024년 3월 11일 22:13:36

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dp[100001][5][5] = {0};
int n, arr[5][5] = {{0, 2, 2, 2, 2}, {0, 1, 3, 4, 3}, {0, 3, 1, 3, 4}, {0, 4, 3, 1, 3}, {0, 3, 4, 3, 1}};

int main() {
    vector<int> vt;
    cin >> n;
    while(n != 0) {
        vt.push_back(n);
        cin >> n;
    }
    priority_queue<pair<pair<int, int>, pair<int, int>>> pq;
    pq.push({{0, 0}, {0, 0}});
    fill(&dp[0][0][1], &dp[100000][4][4]+1, -1e9);
    while(!pq.empty()) {
        int w = pq.top().first.first;
        int i = pq.top().first.second;
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        pq.pop();
        if(dp[i][a][b] > w) continue;
        if(i == vt.size()) {
            cout << w * -1;
            break;
        }
        if(dp[i+1][vt[i]][b] < w - arr[a][vt[i]]) {
            dp[i+1][vt[i]][b] = w - arr[a][vt[i]];
            pq.push({{w-arr[a][vt[i]], i+1}, {vt[i], b}});
        }
        if(dp[i+1][a][vt[i]] < w - arr[b][vt[i]]) {
            dp[i+1][a][vt[i]] = w - arr[b][vt[i]];
            pq.push({{w-arr[b][vt[i]], i+1}, {a, vt[i]}});
        }
    }
    return 0;
    // cal(0, 0, 0, 0);
    // cout << ans;
}