//11720 숫자의 합 - C++17
//메모리 : 2024KB / 시간 : 0ms
//2023년 6월 6일 15:10:09

#include <iostream>

using namespace std;

int main()
{
    int N, result=0;
    string str;
    
    cin >> N >> str;
    for(int i=0;i<N;i++) {
        result = result + int(str[i])- 48;
    }
    cout << result << endl;

    return 0;
}