//11170 0의 개수 - C++17
//메모리 : 2020KB / 시간 : 112ms
//2024년 8월 9일 01:55:15

#include <iostream>
#include <string>
using namespace std;
 
int main() {
    int test, a, b, i, j, k;
    cin >> test;
    for(i=0;i<test;i++){ 
        cin >> a >> b;
        int cnt = 0, sum = 0;
        for(j=a;j<=b;j++){
            string str = to_string(j);
            for(k=0;k<str.length();k++)
                if(str[k]=='0') cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}