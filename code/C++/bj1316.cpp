//1316 그룹 단어 체커 - C++17
//메모리 : 2024KB / 시간 : 0ms
//2024년 1월 29일 19:25:30

#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    int n, i, j, answer = 0;
    cin >> n;
    for(i=0;i<n;i++) {
        int ck = 0, arr[26] = {0};
        string str;
        cin >> str;
        arr[str[0]-'a']++;
        for(j=0;j<str.size()-1;j++) {
            if(str[j] == str[j+1]) continue;
            arr[str[j+1]-'a']++;
            if(arr[str[j+1]-'a'] == 2)
                ck = 1;
        }
        if(ck) answer++; 
    }
    cout << n - answer;
    return 0;
}