//2775 부녀회장이 될테야 - C++17
//메모리 : 2020KB / 시간 : 84ms
//2024년 6월 17일 02:06:16

#include <iostream>
using namespace std;

int getNum(int x, int y) {
	if(y == 1) return 1;
	if(x == 0) return y;
	return (getNum(x - 1, y) + getNum(x, y - 1));
}

int main() {
	int t, k, n, i;
	cin >> t;
	for (i = 0;i<t;i++) {
		cin >> k >> n;
		cout << getNum(k, n) << "\n";
	}
}