//2839 설탕 배달 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 6월 18일 00:58:03

#include <iostream>
using namespace std;

int main() {
	int n, ans = 0;
    cin >> n;
	while(n >= 0) {
		if (n % 5 == 0) {
			ans += (n / 5);
			cout << ans;
			return 0;
		}
		n -= 3;
		ans++;
	}
	cout << "-1";
    return 0;
}