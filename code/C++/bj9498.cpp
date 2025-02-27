//9498 시험 성적 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2023년 6월 4일 22:50:03

#include <iostream>

using namespace std;

int main()
{
    int score;
    cin >> score;
    if (score >= 90 && score <= 100) cout << "A";
    else if (score >= 80 && score < 90) cout << "B";
    else if (score >= 70 && score < 80) cout << "C";
    else if (score >= 60 && score < 70) cout << "D";
    else cout << "F";
    
    return 0;
}