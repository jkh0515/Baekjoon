//15736 청기 백기 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2025년 1월 3일 19:26:27

#include <iostream>
#include <string.h>
#include <vector>
#include <set>
using namespace std;
int n, result = 0;

int main() {
    cin >> n;
    for(int i = 1; i * i <= n; i++) {
        result++;
    }
    cout << result;
    return 0;
}