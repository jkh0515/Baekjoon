//6143 문자열 생성 2 - C++17
//메모리 : 2288KB / 시간 : 648ms
//2024년 3월 2일 17:43:36

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, i;
    deque<int> dq;
    queue<char> ans;
    char str;
    cin >> n;
    int f = 0, e = n - 1;
// 	cout << f << " " << e;
    for(i=0;i<n;i++) {
        cin >> str;
        dq.push_back(str);
    }
    while(f <= e) {
		if(dq[f] < dq[e]) ans.push(dq[f++]);
		else if(dq[f] > dq[e]) ans.push(dq[e--]);
		else {
			int pi = f + 1, pj = e - 1;
			while(pj - pi > 1 and dq[pi] == dq[pj]) pi++, pj--;
			if(pj >= 0 and pi < dq.size() and dq[pi] < dq[pj]) ans.push(dq[f++]);
			else ans.push(dq[e--]);
		}
	}
	n = ans.size();
    for(i=1;i<=n;i++) {
        cout << ans.front();
        ans.pop();
        if(i % 80 == 0) cout << "\n";
    }
    return 0;
}