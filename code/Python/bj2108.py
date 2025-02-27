#2108 통계학 - PyPy3
#메모리 : 111656KB / 시간 : 272ms
#2025년 2월 16일 05:16:44

n = int(input())
s = int(0)
li = [0 for i in range(8002)]
cn = int(0)
o = int(0)
ck = int(0)
a, b, c, d = 0, 8002, 8002, 8002
for i in range(n) :
    a = int(input())
    li[a + 4000] += 1
    s += a
    o = max(o, li[a + 4000])
for i in range(8001) :
    cn += li[i]
    if cn >= n // 2 + 1 and b == 8002:
        b = i - 4000
    if li[i] == o :
        if ck < 2 :
            c = i - 4000
            ck += 1
    if li[i] != 0 :
        if d == 8002 :
            d = i
        a = max(a, i)
print(round(s / n))
print(b)
print(c)
print(a - d)
