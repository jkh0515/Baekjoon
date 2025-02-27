//2231 분해합 - C++17
//메모리 : 2024KB / 시간 : 0ms
//2023년 6월 8일 00:25:08

#include <iostream>

using namespace std;

int main()
{
    int N, len, a = 0, b = 0;
    string num, result;
    cin >> num;
    len = num.length();
    N = stoi(num) - 9*len;
    for(int i=N;i<stoi(num);i++) {
        result = to_string(i);
        a = i;
        for(int j=0;j<result.length();j++) {
            a = a + int(result[j]) - 48;
            // cout << int(result[j]) - 48 << "  ";
        }  
        // cout << i << "  " << a << endl;
        if(a == stoi(num)) {
            cout << i;
            b = 1;
            break;
        }
    }
    if(b == 0) {
        cout << b;
    }

    return 0;
}