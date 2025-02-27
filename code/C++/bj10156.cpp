//10156 과자 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 8월 8일 02:04:52

#include <iostream>
using namespace std;
int main() {
    int c, n, m;
    cin >> c >> n >> m;
    int ans = (c * n) - m;
    if(ans > 0) cout<<ans;
    else cout << "0" ;
    return 0;
}