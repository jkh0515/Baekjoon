#15686 치킨 배달 - Python 3
#메모리 : 39508KB / 시간 : 304ms
#2025년 3월 12일 02:03:13

from queue import PriorityQueue

n, m = map(int, input().split())
ckli, mli, hi, r = [], [], 1, 2e9
tx, ty = [1, -1, 0, 0], [0, 0, 1, -1]
for i in range(n) :
    mli.append(list(map(int, input().split())))
    for j in range(n) :
        if mli[i][j] == 1 :    
            mli[-1][j] = -hi
            hi += 1
        if mli[i][j] == 2 :
            ckli.append([i, j])
dli = [[0 for _ in range(hi - 1)] for _ in range(len(ckli))]
for i in range(len(ckli)) :
    pq = PriorityQueue()
    dp = [[0 for _ in range(n)] for _ in range(n)]
    pq.put([1, ckli[i][0], ckli[i][1]])
    while pq.empty() == False :
        v, _x, _y = pq.get()
        for j in range(4) :
            x = _x + tx[j]
            y = _y + ty[j]
            if x < 0 or x >= n or y < 0 or y >= n : continue
            if dp[x][y] == 1 : continue
            dp[x][y] = 1
            if mli[x][y] < 0 :
                dli[i][-mli[x][y] - 1] = v
            pq.put([v + 1, x, y])

def cal(s, f) :
    global hi, r
    if len(s) == m :
        tr = 0
        for j in range(hi - 1) :
            tt = 2e9
            for i in s :
                tt = min(tt, dli[int(i)][j])
            tr += tt
        r = min(r, tr)
    else :
        for i in range(f, min(len(ckli), f + len(ckli) - len(s))) :
            cal(s + [i], i + 1)
        
cal([], 0)
print(r)
