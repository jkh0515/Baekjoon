//1036 36진수 - C++17
//메모리 : 2044KB / 시간 : 0ms
//2024년 3월 1일 00:53:09

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
string sarr[36];
int iarr[91];

class ts {
    private :
    int arr[60] = {0};
    int size = 0;
    public :
    ts(string str) {
        size = str.size();
        for(int i=0;i<str.size();i++)
            arr[str.size()-1-i] = iarr[str[i]];
    }
    int rsize() { return size; }
    int ridx(int idx) { return arr[idx]; }
    void print() {
        for(int i=size-1;i>=0;i--)
            cout << sarr[arr[i]];
    }
    ts operator+(ts tsa) {
        int nsize = max(size, tsa.rsize());
        int narr[60] = {0};
        string nstr = "";
        for(int i=0;i<nsize;i++) {
            narr[i] += arr[i] + tsa.ridx(i);
            if(narr[i] > 35) {
                narr[i+1] += 1;
                narr[i] -= 36;
            }
        }
        if(narr[nsize] != 0) nsize++;
        for(int i=nsize-1;i>=0;i--)
            nstr += sarr[narr[i]];
        return ts(nstr);
    }
    bool operator <(ts tsa) {
        int nsize = max(size, tsa.rsize());
        for(int i=nsize-1;i>=0;i--) {
            if(arr[i] < tsa.ridx(i)) return 0;
            if(arr[i] > tsa.ridx(i)) return 1;
        }
        return 0;
    }
};

int main() {
    int n, k, s = 0, i, j, l;
    string strarr[50];
    int sch[50][36] = {0};
    vector<ts> vt;
    ts answer = ts("");
    for(i=0;i<10;i++) sarr[i] = to_string(i);
    for(i=10;i<36;i++) sarr[i] = 55+i;
    for(i=49;i<58;i++) iarr[i] = i-48;
    for(i=65;i<91;i++) iarr[i] = i-55;
    // bool a = ts("2")<ts("20");
    // cout << a;
    cin >> n;
    for(i=0;i<n;i++) {
        cin >> strarr[i];
        answer = answer + ts(strarr[i]);
        for(j=0;j<strarr[i].size();j++)
            sch[strarr[i].size()-j-1][iarr[strarr[i][j]]]++;
    }
    cin >> k;
    for(i=0;i<36;i++) {
        string strtts = sarr[35-i];
        ts tts = ts("");
        for(j=49;j>=0;j--) {
            if(sch[j][i] == 0) continue;
            for(l=0;l<j;l++) strtts += "0";
            for(l=0;l<sch[j][i];l++) tts = tts + ts(strtts);
            strtts = sarr[35-i];
        }
        vt.push_back(tts);
    }
    sort(vt.begin(), vt.end());
    for(i=0;i<k;i++) {
        if(i >= vt.size()) break;
        answer = answer + vt[i];
        // vt[i].print();
        // cout << endl;
    }
    answer.print();
    return 0;
}
