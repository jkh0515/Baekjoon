//1834 나머지와 몫이 같은 수 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 7월 24일 03:51:29

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	unsigned long long N;
	cin >> N;
	if (N == 1) {
		cout << 0;
	}
	else {
		const unsigned long long answer = ((N - 1) * N * (N + 1)) / 2;
		cout << answer;
	}
    return 0;
}