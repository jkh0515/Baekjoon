//2104 부분배열 고르기 - C++17
//메모리 : 9832KB / 시간 : 16ms
//2024년 4월 20일 20:52:08

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n, i, arr[1000000] = {0};

ll divq(int start, int end) {
    if(start == end) return arr[start] * arr[start];
    int mid = (start + end) / 2;
    ll lm = divq(start, mid), rm = divq(mid+1, end);
    ll ans = max(lm, rm), left = mid, right = mid + 1;
    ll mm = min(arr[left], arr[right]), msum = arr[left] + arr[right];
    ans = max(ans, mm * msum);
    while(right < end or left > start) {
        if(right < end and (start == left or arr[left-1] < arr[right+1])) {
            right++;
            msum += arr[right];
            mm = min(mm, arr[right]);
        }
        else {
            left--;
            msum += arr[left];
            mm = min(mm, arr[left]);
        }
        ans = max(ans, mm * msum);
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(i=0;i<n;i++)
        cin >> arr[i];
    cout << divq(0, n-1);
    return 0;
}