#1197 최소 스패닝 트리 - Python 3
#메모리 : 59096KB / 시간 : 3284ms
#2025년 3월 6일 11:56:22

v, e = map(int, input().split())
un, li, r = [i for i in range(v+1)], [[] for _ in range(v)], 0
li = sorted([list(map(int, input().split())) for i in range(e)], key = lambda x:x[2])
for i in li :
    a, b = i[0], i[1]
    while(un[i[0]] != i[0]) : i[0] = un[i[0]]
    while(un[i[1]] != i[1]) : i[1] = un[i[1]]
    un[a] = un[i[0]]
    un[b] = un[i[1]]
    if un[i[0]] == un[i[1]] : continue
    un[i[0]] = un[i[1]] = min(un[i[0]], un[i[1]])
    r += i[2]
print(r)