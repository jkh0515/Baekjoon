//17219 비밀번호 찾기 - C++17
//메모리 : 16680KB / 시간 : 236ms
//2024년 3월 24일 02:39:13

#include <iostream>
#include <map>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, i;
    map<string, string> ma;
    string a, b;
    cin >> n >> m;
    for(i=0;i<n;i++) {
        cin >> a >> b;
        ma[a] = b;
    }
    for(i=0;i<m;i++) {
        cin >> a;
        cout << ma[a] << "\n";
    }
    return 0;
}