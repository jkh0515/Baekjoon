//19539 사과나무 - C++17
//메모리 : 2020KB / 시간 : 32ms
//2024년 8월 1일 01:33:46

#include <iostream>
using namespace std;

int main() {
    int n, i, now, two = 0, sum = 0;
    cin >> n ;
    for(i = 0 ; i < n ; i++) {
        cin >> now ;
        sum += now ;
        two += now / 2 ;
    }
    if(sum % 3 != 0 or sum / 3 > two) cout << "NO\n" ;
    else cout << "YES\n" ;
    return 0;
}