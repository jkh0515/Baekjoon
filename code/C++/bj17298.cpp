//17298 오큰수 - C++17
//메모리 : 16104KB / 시간 : 208ms
//2024년 4월 5일 20:06:55

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, i, ans[1000000], arr[1000000];
vector<int> vt(1, 0);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(i=0;i<n;i++)
        cin >> arr[i];
    for(i=1;i<n;i++) {
        while(vt.size() > 0 and arr[vt.back()] < arr[i]) {
            ans[vt.back()] = arr[i];
            vt.pop_back();
        }
        vt.push_back(i);
    }
    for(i=0;i<vt.size();i++)
        ans[vt[i]] = -1;
    for(i=0;i<n;i++)
        cout << ans[i] << " ";
}