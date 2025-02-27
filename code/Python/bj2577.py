#2577 숫자의 개수 - Python 3
#메모리 : 32412KB / 시간 : 36ms
#2025년 2월 14일 18:52:22

a = int(input())
a *= int(input())
a *= int(input())
for i in range(0, 10) :
    print(str(a).count(str(i)))
