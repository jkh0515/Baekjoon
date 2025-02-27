//2562 최댓값 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2023년 6월 6일 14:55:51

#include <iostream>

using namespace std;

int main()
{
    int max, temp, idx=1;
    cin >> max;
    for(int i=2;i<10;i++) {
        cin >> temp;
        if(temp > max) {
            max = temp;
            idx = i;
        }
    }
    cout << max << endl << idx;

    return 0;
}