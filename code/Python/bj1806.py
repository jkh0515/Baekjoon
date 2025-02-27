#1806 부분합 - Python 3
#메모리 : 42168KB / 시간 : 100ms
#2025년 2월 14일 21:59:21

n, s = map(int, input().split())
li = list(map(int, input().split()))
a, b, c = int(0), int(0), int(1e9)
for i in range(len(li)) :
    a += li[i]
    while(a >= s and b <= i) :
        c = min(c, i - b + 1)
        a -= li[b]
        b += 1
print(c if c != 1e9 else 0)