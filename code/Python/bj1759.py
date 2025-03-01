#1759 암호만들기 - Python 3
#메모리 : 32412KB / 시간 : 36ms
#2025년 3월 2일 00:05:53

L, C = map(int, input().split())
li, t = sorted(input().split()), C - L + 1
ck = ["a", "e", "i", "o", "u"]

def makePassword(a, b, c, d, e) :
    if len(a) == L and d >= 1 and e >= 2 : print(a)
    else :
        for i in range(b, b + t) :
            if i >= C : continue
            if li[i] in ck : makePassword(a + li[i], i + 1, c - 1, d + 1, e)
            else : makePassword(a + li[i], i + 1, c - 1, d, e + 1)

makePassword("", 0, L, 0, 0)