//3052 나머지 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2023년 6월 6일 17:00:51

#include <iostream>

using namespace std;

int main()
{
    int arr[10], state = 1, temp[10], idx = 1;
    for(int i=0;i<10;i++) {
        cin >> arr[i];
        arr[i] = arr[i]%42;
        // cout << arr[i] << " ";
    }
    // cout << endl;
    temp[0] = arr[0];
    for(int i=1;i<10;i++) {
        for(int j=0;j<idx;j++) {
            if(arr[i] == temp[j]) {
                state = 1;
                break;
            }
            else {
                state = 0;
            }
        }
        if(state == 0) {
            temp[idx] = arr[i];
            idx++;
            // cout << temp[idx] << " ";
            
        }
    }    
    // cout << endl;
    // for(int i=0;i<10;i++) {
    //     cout << temp[i] << " ";
    // }
    cout << idx;
    
    return 0;
}