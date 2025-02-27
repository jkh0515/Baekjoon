//1978 소수 찾기 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2023년 6월 8일 20:24:54

#include <iostream>
using namespace std;

int main() {
	int N, result = 0;
	int temp, cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		for (int div = 1; div <= temp; div++) {
			if (temp%div == 0)
				cnt++;
		}
		if (cnt == 2)	//temp가 소수
			result++;
		cnt = 0;
	}
	cout << result << '\n';
}