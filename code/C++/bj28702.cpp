//28702 FizzBuzz - C++17
//메모리 : 2024KB / 시간 : 0ms
//2024년 6월 9일 21:29:24

#include <iostream>
using namespace std;

int main() {
    string a[3];
    int t = 0, n, i, m = 0;
    cin >> a[0] >> a[1] >> a[2];
    for(i=0,n=3;i<3;i++,n--)
        if(a[i][0]-'0' < 10) {
            t = stoi(a[i]) + n;
    }
    if(t % 3 == 0) {
        cout << "Fizz";
        m++;
    }
    if(t % 5 == 0) {
        cout << "Buzz";
        m++;
    }
    if(m == 0) cout << t;
    return 0;
}