//1436 영화감독 숌 - C++17
//메모리 : 2020KB / 시간 : 72ms
//2024년 6월 15일 05:06:01

#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
	int title, ck = 0, n;
	string stitle;
	cin >> n;
	for (title = 666; ; title++) {
		stitle = to_string(title);
		if (stitle.find("666") != -1) {
            ck++;
			if(ck == n) {
				cout << title;
				break;
			}
		}
	}
	return 0;
}