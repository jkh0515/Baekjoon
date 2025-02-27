//7432 디스크 트리 - C++17
//메모리 : 10360KB / 시간 : 56ms
//2024년 4월 27일 19:21:36

#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

typedef struct node {
    priority_queue<string, vector<string>, greater<string>> pq;
    map<string, node> ma;
} node;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, i, j;
    cin >> n;
    string str;
    node head;
    vector<node> prev;
    while(n--) {
        cin >> str;
        vector<int> sl(1, -1);
        vector<string> vt;
        for(i=0;i<str.size();i++)
            if(str[i] == 92) sl.push_back(i);
        sl.push_back(str.size());
        for(i=0;i<sl.size()-1;i++)
            vt.push_back(str.substr(sl[i]+1, sl[i+1]-sl[i]-1));
        node *now = &head;
        for(i=0;i<vt.size();i++) {
            if(now->ma.find(vt[i]) == now->ma.end()) {
                now->pq.push(vt[i]);
                node newNode;
                now->ma[vt[i]] = newNode;
            }
            now = &now->ma[vt[i]];
        }
    }
    prev.push_back(head);
    while(prev.size() > 0) {
        if(prev.back().pq.empty()) {
            prev.pop_back();
            continue;
        }
        string top = prev.back().pq.top();
        prev.back().pq.pop();
        prev.push_back(prev.back().ma[top]);
        for(i=2;i<prev.size();i++) cout << " ";
        cout << top << "\n";
    }
    return 0;
}