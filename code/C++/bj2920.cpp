//2920 음계 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2023년 6월 6일 16:34:13

#include <iostream>

using namespace std;

int main()
{
    int arr[8], state;
    for(int i=0;i<8;i++) {
        cin >> arr[i];
    }
    if(arr[1] - arr[0] == 1) {
        state = 1;
        for(int i=1;i<8;i++) {
            if(arr[i]-arr[i-1] == 1 && state == 1) {
                state = 1;
            }
            else state = 0;
        }
    }
    else if(arr[1] - arr[0] == -1){
        state = -1;
        for(int i=1;i<8;i++) {
            if(arr[i]-arr[i-1] == -1 && state == -1) {
                state = -1;
            }
            else state = 0;
        }
    }
    if (state == 1) cout << "ascending";
    else if(state == -1) cout << "descending";
    else cout << "mixed";
    
    return 0;
}