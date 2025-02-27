//16481 원 전문가 진우 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 8월 19일 01:18:44

#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	double r1, r2, r3;
	cin >> r1 >> r2 >> r3;
	cout.setf(ios::fixed);
	cout.precision(10);
	cout << (r1 * r2 * r3) / (r1 * r2 + r1 * r3 + r2 * r3);
}