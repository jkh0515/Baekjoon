//10818 최소, 최대 - C++17
//메모리 : 2020KB / 시간 : 460ms
//2023년 6월 6일 15:04:21

#include <iostream>

using namespace std;

int main()
{
    long int N, min, max, temp;
    cin >> N;
    cin >> temp;
    max = temp;
    min = temp;
    for(int i=1;i<N;i++) {
        cin >> temp;
        if(temp > max) max = temp;
        if(temp < min) min = temp;
    }
    cout << min << " " << max;

    return 0;
}