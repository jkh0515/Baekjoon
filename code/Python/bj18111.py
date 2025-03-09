#18111 마인크래프트 - PyPy3
#메모리 : 113980KB / 시간 : 396ms
#2025년 3월 10일 02:22:37

n, m, b = map(int, input().split())
r, h = 2e9, 0
li, maxH, minH, r, h = [], 0, 257, 2e9, 0
for i in range(n) :
    tli = list(map(int, input().split()))
    tdict = {}
    for j in tli :
        if j in tdict : tdict[j] += 1
        else : tdict[j] = 1
        maxH = max(maxH, j)
        minH = min(minH, j)
    li.append(tdict)
for i in range(minH, maxH + 1) :
    s, tb = 0, b
    for j in range(n) :
        for k, v in li[j].items() :
            t = (k - i) * v
            if t > 0 : s += t * 2
            else : s -= t
            tb += t
    if tb < 0 : continue
    if r >= s : 
        r = s
        h = i
print(r, h)