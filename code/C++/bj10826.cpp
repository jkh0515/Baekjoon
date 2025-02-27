//10826 피보나치 수 4 - C++17
//메모리 : 18052KB / 시간 : 116ms
//2024년 8월 12일 02:32:00

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string sum(string x, string y) {
	int num, carry = 0;
	string result;

	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());

	while (x.length() < y.length()) x += '0';
	while (x.length() > y.length()) y += '0';

	for (int i = 0; i < x.length(); ++i) {
		num = (x[i] - '0' + y[i] - '0' + carry) % 10;
		result += to_string(num);
		carry = (x[i] - '0' + y[i] - '0' + carry) / 10;
	}
	if (carry != 0) {
		result += to_string(carry);
	}

	reverse(result.begin(), result.end());

	return result;
}

int main() {
	int n;
	string DP[10010];
	cin >> n;
	DP[0] = '0';
	DP[1] = '1';
	for (int i = 2; i <= n; ++i)
		DP[i] = sum(DP[i - 1], DP[i - 2]);
	cout << DP[n] << endl;
    return 0;
}