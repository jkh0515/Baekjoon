#18110 solved.ac - PyPy3
#메모리 : 120268KB / 시간 : 224ms
#2025년 2월 25일 19:39:31

n = int(input())
li, a = sorted([int(input()) for _ in range(n)]), int(n * .15 + .5)
print(int(sum(li[a:n-a]) / (n - a * 2 or 1) + .5))