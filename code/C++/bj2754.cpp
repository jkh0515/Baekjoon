//2754 학점계산 - C++17
//메모리 : 2024KB / 시간 : 0ms
//2023년 6월 5일 23:36:09

#include <iostream>

using namespace std;

int main() {
    string C[13] = {"A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D+", "D0", "D-", "F"};
    string score[13] = {"4.3", "4.0", "3.7", "3.3", "3.0", "2.7", "2.3", "2.0", "1.7", "1.3", "1.0", "0.7", "0.0"};
    string student;
    cin >> student;
    for(int i=0;i<13;i++) {
        if(!student.compare(C[i])) {
            cout << score[i];
            break;
        }
    }
    
    return 0;
}