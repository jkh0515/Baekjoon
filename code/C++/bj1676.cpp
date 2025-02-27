//1676 팩토리얼 0의 개수 - C++17
//메모리 : 2024KB / 시간 : 0ms
//2024년 4월 23일 04:25:03

#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, i, j, t = 0;
    string str;
    long long ans = 0;
    cin >> n;
    if(n > 0) ans = 1;
    for(i=2;i<=n;i++) {
        ans *= (long long)i;
        str = to_string(ans);
        j = str.size() - 1;
        while(str[j] == '0') {
            t++;
            j--;
        }
        if(str.size() > 10) str = str.substr(5, j-4);
        else str = str.substr(0, j+1);
        ans = stoll(str);
        // cout << i << " " << ans << endl;
    }
    cout << t;
    return 0;
}