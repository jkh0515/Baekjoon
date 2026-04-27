//10432 데이터 스트림의 섬 - C++17
//메모리 : 2020KB / 시간 : 24ms
//2026년 4월 13일 14:34:07

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int p, arr[10] = {0};
    cin >> p;
    for(int i=1;i<=p;i++) {
        int result = 0;
        vector<int> vt(1, 0);
        cin >> arr[0] >> arr[0];
        for(int j=0;j<10;j++) {
            cin >> arr[j];
            if(vt.back() != arr[j]) {
                while(vt.back() > arr[j]) {
                    vt.pop_back();
                    result++;
                }
                if(vt.back() < arr[j]) {
                    vt.push_back(arr[j]);
                }
            }
        }
        cin >> arr[0];
        cout << i << " " << result + vt.size() - 1 << "\n";
    }
}