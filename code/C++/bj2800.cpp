//2800 괄호 제거 - C++17
//메모리 : 2308KB / 시간 : 0ms
//2024년 5월 3일 23:22:22

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int carr[21] = {0, }, arr[200], len;
priority_queue<string, vector<string>, greater<string>> pq;
string str;
vector<string> list;

void combination(int depth, int next, int r, int n){
    if(depth == r){
        int i, ch[11] = {0};
        string now = "";
        for(i=0;i<r;i++) ch[carr[i]] = 1;
        for(i=0;i<len;i++) if(ch[arr[i]] == 0) now += str[i];
        pq.push(now);
        // cout << now << endl;
        return;
    }
    for(int i=next;i<=n;i++){
        carr[depth] = i;
        combination(depth+1, i+1, r, n);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int i, j, k;
    vector<pair<int, int>> vt;
    cin >> str;
    len = str.size();
    for(i=0,j=0,k=1;i<len;i++) {
        if(arr[i] > 0) continue;
        if(str[i] == '(') j = i;
        else if(str[i] == ')') {
            vt.push_back({j, i});
            arr[i] = k, arr[j] = k;
            k++;
            i = -1;
        }
    }
    for(i=1;i<k;i++) combination(0, 1, i, k-1);
    list.push_back(pq.top());
    while(!pq.empty()) {
        if(list.back() != pq.top()) list.push_back(pq.top());
        pq.pop();
    }
    for(i=0;i<list.size();i++)
        cout << list[i] << "\n";
    return 0;
}