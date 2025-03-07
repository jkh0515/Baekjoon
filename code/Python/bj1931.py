#1931 회의실 배정 - Python 3
#메모리 : 61144KB / 시간 : 2688ms
#2025년 3월 8일 05:03:00

n, t, r = int(input()), -1, 0
li = sorted([list(map(int, input().split())) for _ in range(n)], key=lambda x : (x[1], x[0]))
for i in li :
    if t <= i[0] :
        r += 1
        t = i[1]
print(r)