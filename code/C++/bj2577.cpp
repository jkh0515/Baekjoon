//2577 숫자의 개수 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2023년 6월 6일 16:23:10

#include <iostream>

using namespace std;

int main()
{
    int num[10] = {0};
    int a, b, c, result;
    string cal;
    cin >> a >> b >> c;
    cal = to_string(a*b*c);
    for(int i=0;i<cal.length();i++) {
        // cout << int(cal[i])-48 << " ";
        num[int(cal[i])-48] ++;
    }
    for(int i=0;i<10;i++) {
        cout << num[i] << endl;
    }    
    return 0;
}