//2750 수 정렬하기 - C++17
//메모리 : 41084KB / 시간 : 0ms
//2023년 8월 6일 13:18:11

//수 정렬3

#include <iostream>
using namespace std;
int arr[10000000];

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    for(int i=0;i<n-1;i++) {
        int max = arr[i];
        for(int j=i;j<n;j++) {
            if(max > arr[j]) {
                int temp = max;
                max = arr[j];
                arr[j] = temp;
            }
        }
        arr[i] = max;
    }
    for(int i=0;i<n;i++) {
        // cout << arr[i] << " ";
        printf("%d\n", arr[i]);
    }
    return 0;
}