//10809 알파벳 찾기 - C++17
//메모리 : 2024KB / 시간 : 0ms
//2023년 6월 6일 17:24:06

#include <iostream>

using namespace std;

int main()
{
    int alphabet[26] = {-1, -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    string str;
    cin >> str;
    for(int i=0;i<str.length();i++) {
        // cout << str[i]-97 << " ";
        if(alphabet[str[i]-97] == -1) alphabet[str[i]-97] = i;
    }
    // cout << endl;
    for(int i=0;i<26;i++) {
        cout << alphabet[i] << " ";
    }
    
    return 0;
}