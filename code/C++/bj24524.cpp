//24524 아름다운 문자열 - C++17
//메모리 : 4916KB / 시간 : 44ms
//2024년 3월 5일 01:04:26

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int tarr[26] = {0}, carr[28] = {0};
    string s, t;
    fill(&tarr[0], &tarr[26], 28);
    cin >> s >> t;
    int i, ss = s.size(), ts = t.size();
    for(i=0;i<ts;i++)
        tarr[t[i]-'a'] = i;
    for(i=0;i<ss;i++) {
        if(tarr[s[i]-'a'] == 0) carr[0]++;
        else if(carr[tarr[s[i]-'a']-1] > 0) {
            carr[tarr[s[i]-'a']-1]--;
            carr[tarr[s[i]-'a']]++;
        }
    }
    cout << carr[ts-1];
    return 0;
}