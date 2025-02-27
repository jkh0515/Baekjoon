//25427 DKSH를 찾아라 - C++17
//메모리 : 5744KB / 시간 : 808ms
//2024년 3월 16일 21:54:31

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, i, a, b, c;
    long long dp[4][100001], ans = 0;
    vector<int> d, k, s, h;
    char ch;
    fill(&dp[0][0], &dp[3][100001], -1);
    cin >> n;
    for(i=0;i<n;i++) {
        cin >> ch;
        if(ch == 'D') d.push_back(i);
        else if(ch == 'K') k.push_back(i);
        else if(ch == 'S') s.push_back(i);
        else if(ch == 'H') h.push_back(i);
    }
    for(a=0;a<d.size();a++) {
        long long ta = 0;
        for(b=0;b<k.size();b++) {
            if(k[b] < d[a]) continue;
            // cout << a << " " << b << endl;
            if(dp[1][b] != -1) {
                ta += dp[1][b];
                // cout << ta << endl;
                continue;
            }
            long long tc = 0;
            for(c=0;c<s.size();c++) {
                if(s[c] < k[b]) continue;
                if(dp[2][c] != -1) {
                    tc += dp[2][c];
                    continue;
                }
                long long it = 0;
                for(i=0;i<h.size();i++) {
                    if(h[i] < s[c]) continue;
                    if(dp[3][i] == -1)
                        dp[3][i] = h.size() - i;
                    it += dp[3][i];
                    break;
                }
                dp[2][c] = it;
                tc += it;
            }
            dp[1][b] = tc;
            ta += tc;
        }
        dp[0][a] = ta;
    }
    for(i=0;i<d.size();i++) {
        // cout << dp[0][i] << " ";
        ans += dp[0][i];
    }
    cout << ans;
    return 0;
}