//27447 주문은 토기입니까? - C++17
//메모리 : 10012KB / 시간 : 140ms
//2026년 4월 6일 11:19:15

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int pop_q(queue<int> &q, int mode = 0) {
    if(q.size() > 0) {
        int t = q.front();
        if(mode == 1) {
            q.pop();
        }
        return t;
    }
    else {
        return -1;
    }
}

int pop_vt(vector<int> &vt, int mode = 0) {
    if(vt.size() > 0) {
        int t = vt.back();
        if(mode == 1) {
            vt.pop_back();
        }
        return t;
    }
    else {
        return -1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, t1, t2, time, fail = 0;
    vector<int> vt1;
    queue<int> q1, q2;
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++) {
        scanf("%d", &t1);
        vt1.push_back(t1);
    }
    time = pop_vt(vt1);
    for(int i=time;i>=0;i--) {
        if(i == pop_vt(vt1)) {
            pop_vt(vt1, 1);
            q1.push(i);
            if(pop_q(q1) - i > m) {
                fail = 1;
                break;
            }
        }
        else {
            t1 = pop_q(q1, 1);
            if(t1 != -1) {
                if(t1 - i > m) {
                    fail = 1;
                    break;
                }
                q2.push(t1);
            }
            else {
                pop_q(q2, 1);
            }
        }
    }
    if(q1.size() > 0 || q2.size() > 0) {
        fail = 1;
    }
    if(fail) {
        printf("fail\n");
    }
    else {
        printf("success\n");
    }
    return 0;
}