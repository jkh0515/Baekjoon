//12933 오리 - C++17
//메모리 : 2028KB / 시간 : 0ms
//2024년 7월 19일 01:33:40

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int arr[5] = {0}, now = 0, ans = 0, fin = 0;
    string str;
    map<int, int> ma;
    ma['q'] = 0, ma['u'] = 1, ma['a'] = 2, ma['c'] = 3, ma['k'] = 4;
    cin >> str;
    for(int i=0;i<str.size();i++) {
        int t = ma[str[i]];
        if(t == 0) {
            if(now < ans) fin++;
            arr[t]++, now++;
        }
        else {
            if(arr[t-1] > 0) {
                arr[t-1]--, arr[t]++;
                if(t == 4) now--;
            }
            else {
                cout << "-1";
                return 0;
            }
        }
        ans = max(ans, now);
    }
    if(arr[0] + arr[1] + arr[2] + arr[3] > 0) cout << "-1";
    else cout << arr[4] - fin;
    return 0;
}