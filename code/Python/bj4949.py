#4949 균형잡힌 세상 - Python 3
#메모리 : 32412KB / 시간 : 276ms
#2025년 2월 25일 02:51:32

a = input()
dic = {'[' : 1, ']' : -1, '(' : 2, ')' : -2}
while a != '.' :
    li, b = list(), True
    for i in a :
        if i in dic :
            li.append(dic[i])
            while len(li) > 0 and li[-1] < 0 :
                if len(li) >=2 and li[-2] == -li[-1] :
                    li.pop()
                    li.pop()
                else :
                    b = False
                    break
    if b == False or len(li) != 0:
        print("no")
    else :
        print("yes")
    a = input()