#1167 트리의 지름 - Python 3
#메모리 : 90264KB / 시간 : 3188ms
#2025년 3월 14일 03:35:53

v = int(input())
li, r= [[] for _ in range(v)], -1
for _ in range(v) :
    info, i = list(map(int, input().split())), 1
    while info[i] != -1 :
        li[info[0] - 1].append([info[i] - 1, info[i+1]])
        i += 2

def cal(idx) :
    dp = [-1 for _ in range(v)]
    q = [[idx, 0]]
    dp[idx] = 0
    while len(q) :
        t, d = q.pop()
        for i in li[t] :
            _t, _d = i
            if dp[_t] == -1 :
                dp[_t] = _d + d
                q.append([_t, _d + d])
    return dp

start = cal(0)
print(max(cal(start.index(max(start)))))