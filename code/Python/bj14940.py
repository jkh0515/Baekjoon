#14940 쉬운 최단거리 - Python 3
#메모리 : 42912KB / 시간 : 872ms
#2025년 3월 18일 22:56:30

import heapq

n, m = map(int, input().split())
dp, li, sx, sy = [[-1 for _ in range(m)] for _ in range(n)], [], 0, 0
tx, ty = [1, -1, 0, 0], [0, 0, 1, -1]
for i in range(n) :
    tli = list(map(int, input().split()))
    for t in range(len(tli)) :
        if tli[t] == 0 : dp[i][t] = 0
        elif tli[t] == 2 : sx = i; sy = t; dp[sx][sy] = 0
    li.append(tli)
q = [[0, sx, sy]]
while(len(q)) :
    _v, _x, _y = heapq.heappop(q)
    for i in range(4) :
        x = _x + tx[i]
        y = _y + ty[i]
        v = _v + 1
        if x < 0 or x >= n or y < 0 or y >= m : continue
        if dp[x][y] == -1 :
            dp[x][y] = v
            heapq.heappush(q, (v, x, y))
for i in dp :
    for j in i :
        print(j, end = " ")
    print()