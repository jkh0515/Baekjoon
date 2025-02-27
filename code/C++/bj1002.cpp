//1002 터렛 - C++17
//메모리 : 2020KB / 시간 : 4ms
//2024년 4월 13일 01:40:52

#include <iostream>
using namespace std;

int main() {
    int i, x1, y1, r1, x2, y2, r2, d, cond1, cond2, num;
    cin >> num;
    for(i=0;i<num;i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        d = (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
        cond1 = (r1-r2) * (r1-r2);
        cond2 = (r1+r2) * (r1+r2);
        if(d == 0) {
            if(cond1 == 0) cout << "-1\n";
            else cout << "0\n";
        }
        else if (d == cond1 or d == cond2) cout << "1\n";
        else if (cond1 < d and d < cond2) cout << "2\n";
        else cout << "0\n";
    }
    return 0;
}