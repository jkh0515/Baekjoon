//9019 DSLR - C++17
//메모리 : 2276KB / 시간 : 3528ms
//2024년 5월 8일 00:19:29

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, a, b;
    cin >> n;
    while(n--) {
        int arr[10001] = {0};
        cin >> a >> b;
        queue<pair<int, string>> q;
        q.push({a, ""});
        while(!q.empty()) {
            int na = q.front().first;
            string nn = q.front().second;
            // cout << len << endl;
            q.pop();
            int d = (na * 2) % 10000, s = na - 1, l, r;
            if(na == b) {
                cout << nn << "\n";
                break;
            }
            if(s < 0) s = 9999;
            l = (na % 1000) * 10 + na / 1000;
            r = na / 10 + (na % 10) * 1000;
            if(arr[d] == 0) {arr[d] = 1; q.push({d, nn+'D'}); }
            if(arr[s] == 0) {arr[s] = 1; q.push({s, nn+'S'}); }
            if(arr[l] == 0) {arr[l] = 1; q.push({l, nn+'L'}); }
            if(arr[r] == 0) {arr[r] = 1; q.push({r, nn+'R'}); }
            // cout << d << " " << s << " " << l << " " << r << endl;
        }
    }
    return 0;
}