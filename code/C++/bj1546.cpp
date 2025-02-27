//1546 평균 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2023년 6월 24일 12:48:19

#include <iostream>

using namespace std;

int main()
{
    int n;
    int score[1000], max = 0;
    float sumScore = 0, final;
    
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> score[i];
        if(score[i] > max) max = score[i];
    }
    // cout << max << endl;
    for(int i=0;i<n;i++) {
        float temp;
        temp = score[i] * 100 / float(max);
        // cout << score[i] << " " << temp << endl;
        sumScore += temp;
    }
    
    final = sumScore / n;
    cout << final;

    return 0;
}
