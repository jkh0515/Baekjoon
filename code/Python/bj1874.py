#1874 스택 수열 - Python 3
#메모리 : 35020KB / 시간 : 2660ms
#2025년 2월 16일 02:47:36

n = int(input())
a = int(1)
ck = True
li = list()
ans = list()
for i in range(n) :
    target = int(input())
    while(target >= a) :
        li.append(a)
        ans.append("+")
        a += 1
    if(li[-1] != target) :
        ck = False
    else :
        ans.append("-")
        li.pop()
if(ck) :
    for i in ans :
        print(i)
else :
    print("NO")