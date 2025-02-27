//8958 OX퀴즈 - C++17
//메모리 : 2024KB / 시간 : 4ms
//2023년 6월 6일 17:09:34

#include <iostream>

using namespace std;

int main()
{
    int n, combo = 0, score;
    string str;
    cin >> n;
    for(int i=0;i<n+1;i++) {
        getline(cin, str);
        score = 0;
        if(i != 0) {
            for(int i=0;i<str.length();i++) {
                if(str[i] == 'O') {
                    combo ++;
                }
                else combo = 0;
                score = score + combo;
            }
            cout << score << endl;
            combo = 0;
        }
    }
    
    return 0;
}