//1018 체스판 다시 칠하기 - C++17
//메모리 : 2028KB / 시간 : 0ms
//2024년 5월 4일 01:00:18

#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;

string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};
string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};

string board[50];

int WB_cnt(int x, int y) {
    int i, j, cnt = 0;
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            if(board[x+i][y+j] != WB[i][j])
                cnt++;
    return cnt;
}

int BW_cnt(int x, int y) {
    int i, j, cnt = 0;
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            if(board[x+i][y+j] != BW[i][j])
                cnt++;
    return cnt;
}

int main() {
    int i, j, size[2], cnt, min_val = 12345;
    pair<int, int> p1;
    cin >> p1.first >> p1.second;
    for(i=0;i<p1.first;i++)
        cin >> board[i];
    for(i=0;i+8<=p1.first;i++) {
        for(j=0;j+8<=p1.second;j++) {
            int tmp;
            tmp = min(WB_cnt(i,j),BW_cnt(i,j));
            if(tmp < min_val) 
                min_val = tmp;
        }
    }
    cout << min_val;
    return 0;
}