//13273 로마숫자 - C++17
//메모리 : 2028KB / 시간 : 172ms
//2024년 2월 25일 20:54:15

#include <iostream>
#include <string>
using namespace std;

// I : 1    V : 5    X : 10     L : 50      C : 100     D : 500      M : 1000
int iarr[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
string sarr[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

int rtoi(string ch) {
    int ans = 0, i = 0, j = 0, k;
    while(j < ch.length()) {
        k = 1;
        string str = ch.substr(j, 2);
        for(i=0;i<13;i++) {
            if(sarr[i] == str) {
                ans += iarr[i];
                k = 0;
                // cout << sarr[i] << " ";
                break;
            }
        }
        if(k) {
            str = ch.substr(j, 1);
            for(i=0;i<13;i++) {
                if(sarr[i] == str) {
                    ans += iarr[i];
                    // cout << sarr[i] << " ";
                    break;
                }
            }
            j--;
        }
        j += 2;
    }
    return ans;
}

string itor(string str) {
    string ans = "";
    int i = 0, ch = stoi(str);
    while(i != 13) {
        if(ch >= iarr[i]) {
            ch -= iarr[i];
            ans += sarr[i];
        }
        else i++;
    }
    return ans;
}

int main() {
    int n;
    string str;
    cin >> n;
    while(n--) {
        cin >> str;
        if(str[0] <= '9') cout << itor(str) << "\n";
        else cout << rtoi(str) << "\n";
    }
    return 0;
}