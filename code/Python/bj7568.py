#7568 덩치 - Python 3
#메모리 : 32412KB / 시간 : 36ms
#2025년 2월 26일 04:09:04

n, a = int(input()), list()
for i in range(n) :
    a.append(list(map(int, input().split(" "))) + [i])
b = [0 for _ in range(n)]
a.sort(reverse = True)
for i in range(len(a)) :
    r = 1
    for j in range(i) :
        if a[i][0] >= a[j][0] or a[i][1] >= a[j][1] : continue
        r += 1
    b[a[i][2]] = r
for i in b :
    print(i, end = " ")