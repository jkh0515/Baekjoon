//1935 후위 표기식2 - C++17
//메모리 : 2024KB / 시간 : 0ms
//2024년 1월 25일 20:33:20

#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    int n, arr[26];
    double a, b;
    vector<double> vt;
    string str;
    cin >> n >> str;
    for(int i=0;i<n;i++)
        cin >> arr[i];;
    for(int i=0;i<str.size();i++) {
        if(str[i] >= 65 and str[i] <= 90) {
            vt.push_back(arr[str[i]-65]);
        }
        else {
            a = vt.back();
            vt.pop_back();
            b = vt.back();
            vt.pop_back();
            if(str[i] == '+')
                vt.push_back(a+b);
            else if(str[i] == '*')
                vt.push_back(a*b);
            else if(str[i] == '-')
                vt.push_back(b-a);
            else vt.push_back((double)b/a);
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << vt.back();
    return 0;
}
