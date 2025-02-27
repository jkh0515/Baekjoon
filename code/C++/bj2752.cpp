//2752 세수정렬 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 6월 6일 22:19:53

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> vt;
    int a;
    for(int i=0;i<3;i++) {
        cin >> a;
        vt.push_back(a);
    }
    sort(vt.begin(), vt.end());
    for(int i=0;i<3;i++) {
        cout << vt[i] << " ";
    }
    return 0;
}