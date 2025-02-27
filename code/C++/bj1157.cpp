//1157 단어 공부 - C++17
//메모리 : 4916KB / 시간 : 40ms
//2023년 6월 6일 16:09:32

#include <iostream>

using namespace std;

int main()
{
    long int alphabet[26] = {0}, max = 0, max2 = 0, idx;
    string str;
    cin >> str;
    for(int i=0;i<str.length();i++) {
        if(str[i] >= 65 && str[i] <= 90) alphabet[str[i]-65] ++;
        else alphabet[str[i]-97] ++;
    }
    for(int i=0;i<26;i++) {
        if(alphabet[i] >= max) {
            max2 = max;
            max = alphabet[i];
            idx = i;
        }
        // cout << alphabet[i];
    }
    // cout << endl << max << endl << max2;
    if(max == max2) cout << "?";
    else cout << char(idx+65);
    // cout << endl << alphabet[max] << endl << alphabet[max2];
    
    return 0;
}