#2675 문자열 반복 - Python 3
#메모리 : 32412KB / 시간 : 36ms
#2025년 2월 14일 19:06:29

n = int(input())
for i in range(n) :
    r, s = input().split()
    for j in s :
        for k in range(int(r)) :
            print(j, end = "")
    print()