//15964 이상한 기호 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2023년 6월 5일 23:50:45

#include <iostream>

using namespace std;

long int funtion(long int A, long int B) {
    return (A+B)*(A-B);
}

int main() {
    long int A, B, result;
    cin >> A >> B;
    result = funtion(A, B);
    cout << result;
    return 0;
}