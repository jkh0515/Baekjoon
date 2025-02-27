//4470 줄번호 - C++17
//메모리 : 2024KB / 시간 : 0ms
//2024년 7월 22일 21:28:25

#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    string word;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {
        getline(cin, word);
        cout << i + 1 << ". " << word << "\n";
    }
    return 0;

}

 

