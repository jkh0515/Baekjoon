#10430 나머지 - Python 3
#메모리 : 30840KB / 시간 : 68ms
#2022년 5월 12일 10:43:48

A,B,C = map(int,input().split())
print((A+B)%C)
print(((A%C) + (B%C))%C)
print((A*B)%C)
print(((A%C) * (B%C))%C)