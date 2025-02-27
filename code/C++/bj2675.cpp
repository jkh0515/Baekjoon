//2675 문자열 반복 - C++17
//메모리 : 2024KB / 시간 : 0ms
//2023년 6월 6일 15:01:41

#include <iostream>

using namespace std;

int main()
{
    int T, R;
    string S;
    
    cin >> T;
    for(int i=0;i<T;i++) {
        cin >> R >> S;
        for(int j=0;j<S.length();j++) {
            for(int k=0;k<R;k++) {
                cout << S[j];
            }
        }
        cout << endl;
    }

    return 0;
}