//9252 LCS 2 - C++17
//메모리 : 5820KB / 시간 : 4ms
//2024년 5월 21일 01:31:04

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int i, j, arr[1001][1001] = {0};
    string a, b, ans = "";
    cin >> a >> b;
    for(i=0;i<a.size();i++) {
        for(j=0;j<b.size();j++) {
            if(a[i] == b[j]) arr[i+1][j+1] = arr[i][j] + 1;
            else arr[i+1][j+1] = max(arr[i+1][j], arr[i][j+1]);
        }
    }
    // for(i=0;i<=a.size();i++) {
    //     for(j=0;j<=b.size();j++) {
    //         cout << arr[i][j] << " "; 
    //     }
    //     cout << endl;
    // }
    i = a.size(), j = b.size();
    while(arr[i][j] > 0) {
        if(arr[i][j] == arr[i-1][j]) i--;
        else if(arr[i][j] == arr[i][j-1]) j--;
        else {
            ans += a[i-1];
            i--, j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << arr[a.size()][b.size()] << "\n" << ans;
    return 0;
}