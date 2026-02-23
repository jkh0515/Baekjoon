//32403 전구 주기 맞추기 - C++17
//메모리 : 1228KB / 시간 : 4ms
//2026년 2월 23일 23:26:26

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, t, a, b, c, result = 0;
    vector<int> vectorT;
    scanf("%d %d", &n, &t);
    for(int i=1;i<=t*t;i++) {
        if(t % i == 0) {
            vectorT.push_back(i);
        }
    }

    for(int i=0;i<n;i++) {
        scanf("%d", &a);
        b = upper_bound(vectorT.begin(), vectorT.end(), a) - vectorT.begin();
        c = a - vectorT[b-1];
        result += b == vectorT.size() ? c : min(c, vectorT[b] - a);
    }

    printf("%d", result);
}