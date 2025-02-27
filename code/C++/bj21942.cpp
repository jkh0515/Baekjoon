//21942 부품 대여장 - C++17
//메모리 : 9848KB / 시간 : 368ms
//2024년 4월 28일 19:50:41

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int calendar[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

int stot(string one, string two) {
    int t = (calendar[stoi(one.substr(5, 2))-1] + stoi(one.substr(8, 2)) - 1) * 1440;
    t += (stoi(two.substr(0, 2)) - 1) * 60 + stoi(two.substr(3, 2)) - 1;
    return t;
}

int main() {
    int n, d = 0, f;
    map<pair<string, string>, long long> ma;
    map<string, long long> ans;
    priority_queue<pair<string, long long>, vector<pair<string, long long>>, greater<pair<string, long long>>> pq;
    string str, one, two, three, four;
    cin >> n >> str >> f;
    d += stoi(str.substr(0, 3)) * 1440 + stoi(str.substr(4, 2)) * 60 + stoi(str.substr(7, 2));
    while(n--) {
        cin >> one >> two >> three >> four;
        if(ma.find({three, four}) == ma.end())
            ma[{three, four}] = stot(one, two) + d;
        else {
            long long bt = stot(one, two) - ma[{three, four}];
            if(bt > 0) ans[four] += bt * f;
            ma.erase({three, four});
        }
    }
    if(ans.size() == 0) cout << "-1";
    else {
        map<string, long long>::iterator iter;
        for(iter=ans.begin();iter!=ans.end();iter++)
            pq.push({iter->first, iter->second});
        while(!pq.empty()) {
            cout << pq.top().first << " " << pq.top().second << "\n";
            pq.pop();
        }
    }
    return 0;
}