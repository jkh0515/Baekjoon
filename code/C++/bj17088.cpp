//17088 등차수열 변환 - C++17
//메모리 : 2412KB / 시간 : 56ms
//2024년 7월 24일 23:49:26

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, ans = -1;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	if(n == 1) {
		cout << 0 << "\n";
		return 0;
	}
	for(int d1 = -1; d1 <=1; ++d1) {
		for(int d2 = -1; d2 <= 1; ++d2) {
			int cnt = 0;
			if (d1 != 0) cnt += 1;
			if (d2 != 0) cnt += 1;
			int first = a[0] + d1, second = a[1] + d2;
			int diff = second - first, cand = second;
			bool ok = false;
			for(int i = 2; i < n; ++i) {
				cand += diff;
				if(a[i] == cand) continue;
				if(a[i] + 1 == cand or a[i] - 1 == cand)
					cnt += 1;
				else {
					ok = true;
					break;
				}
			}
			if(!ok and (ans == -1 or cnt < ans))
				ans = cnt;
		}
	}
	cout << ans << "\n";
	return 0;
}