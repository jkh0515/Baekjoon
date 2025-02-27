//16890 창업 - C++17
//메모리 : 4280KB / 시간 : 40ms
//2024년 5월 7일 02:01:30

#include <iostream>
#include <algorithm>
#include <string>
#include <functional>
#include <deque>
using namespace std;
string a, b, front, back;
deque <char> A, B;

int main() {
	cin >> a >> b;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());

	for (int i = 0; i < (int)(a.size() + 1) / 2; i++) A.push_back(a[i]); // 오름차순
	for (int i = 0; i < b.size() / 2; i++) B.push_back(b[i]); // 내림차순

	for (int i = 0; i < a.size(); i++) {
		if (i % 2) { // 큐브러버 차례
			if (A.empty() || A.front() < B.front()) front += B.front(), B.pop_front(); // 큐브러버의 제일 큰 애가 구사과의 제일 작은 애보다 크면 앞으로 가는게 좋다
			else back += B.back(), B.pop_back();
		}
		else { // 구사과 차례
			if (B.empty() || A.front() < B.front()) front += A.front(), A.pop_front(); // 구사과의 제일 작은 애가 큐브러버의 제일 큰 애보다 작으면 앞으로 가는게 좋다
			else back += A.back(), A.pop_back();
		}
	}

	reverse(back.begin(), back.end());
	cout << front << back;
	return 0;
}