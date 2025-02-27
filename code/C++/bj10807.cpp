//10807 개수 세기 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2023년 6월 5일 00:12:29

#include <iostream>

using namespace std;

int main()
{
    int arr[100];
    int N, v, result = 0;
    
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }
    cin >> v;
    for(int i=0;i<N;i++) {
        if(v == arr[i]) result ++;
    }
    cout << result;
    
    return 0;
}