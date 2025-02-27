//1152 단어의 개수 - C++17
//메모리 : 4916KB / 시간 : 28ms
//2023년 6월 6일 15:46:24

#include <iostream>

using namespace std;

int main()
{
    long int N=1;
    string str;
    getline(cin, str);
    for(int i=0;i<str.length();i++) {
        // if(isspace(str[i])) N ++;
        if(str[i] == ' ') N++;
    }
    if(str[0] == ' ') N--;
    if(str[str.length()-1] == ' ') N--;
    // if (!str.compare(" ")) N = 1;
    cout << N;
    
    return 0;
}