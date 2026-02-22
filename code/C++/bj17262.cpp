//17262 팬덤이 넘쳐흘러 - C++17
//메모리 : 3448KB / 시간 : 40ms
//2026년 2월 22일 23:07:29

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> vectorA, vectorB;
    int n, a, b;

    scanf("%d", &n);

    for(int i=0;i<n;i++) {
        scanf("%d %d", &a, &b);
        vectorA.push_back(a);
        vectorB.push_back(b);
    }

    sort(vectorA.begin(), vectorA.end(), greater<int>());
    sort(vectorB.begin(), vectorB.end());

    printf("%d", vectorA[0] > vectorB[0] ? vectorA[0] - vectorB[0] : 0);

    return 0;
}