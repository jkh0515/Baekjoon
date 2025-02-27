//4101 크냐? - C++17
//메모리 : 2020KB / 시간 : 4ms
//2024년 6월 14일 05:38:45

#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    while(a != 0 and b != 0) {
        if(a > b) cout << "Yes\n";
        else cout << "No\n";
        cin >> a >> b;
    }
    return 0;
}
        