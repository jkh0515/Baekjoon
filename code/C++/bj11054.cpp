//11054 가장 긴 바이토닉 부분 수열 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 3월 25일 16:12:44

#include <iostream>

#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    int n, i, j, d, m = 0, arr[1001], dp[1001], dp2[1001];

    fill(&dp[0], &dp[1001], 1);

    fill(&dp2[0], &dp2[1001], 1);

    cin >> n;

    for(i=0;i<n;i++)

        cin >> arr[i];

    for(i=1;i<n;i++)

        for(j=i;j>=0;j--)

            if(arr[i] > arr[j] and dp[i] < dp[j] + 1)

                dp[i] = dp[j] + 1;

    for(i=n-1;i>=0;i--)

        for(j=i;j<n;j++)

            if(arr[i] > arr[j] and dp2[i] < dp2[j] + 1)

                dp2[i] = dp2[j] + 1;

    for(i=0;i<n;i++) {

        if(m < dp[i]+dp2[i]-1) {

            m = dp[i]+dp2[i]-1;

            d = i;

        }

    }

    cout << m;

    return 0;

}