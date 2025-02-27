//5597 과제 안 내신 분..? - C++17
//메모리 : 2020KB / 시간 : 0ms
//2023년 6월 5일 12:38:32

#include <iostream>

using namespace std;

int main() {
    int arr[30] = {0};
    int temp, a=1;
    
    for(int i=0;i<28;i++) {
        cin >> temp;
        arr[temp-1] = temp; 
    }
    for(int i=0;i<30;i++) {
        if(arr[i] == 0) {
            cout << i+1;
            if(a == 1) cout << endl;
            a--;
        }
    }
}