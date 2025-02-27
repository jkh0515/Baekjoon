//10816 숫자 카드 2 - C++17
//메모리 : 80144KB / 시간 : 292ms
//2024년 4월 30일 00:50:01

#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> ii;
int arr[20000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, t;
    cin >> n;
    while(n--) {
        cin >> t;
        arr[t+10000000]++;
    } 
    cin >> n;
    while(n--) {
        cin >> t;
        cout << arr[t+10000000] << " ";
    }
    return 0;
}