#2096 내려가기 - Python 3
#메모리 : 32412KB / 시간 : 2872ms
#2025년 3월 13일 02:33:14

n = int(input())
minArr = maxArr = list(map(int, input().split()))
for _ in range(n - 1) :
    inputArr = list(map(int, input().split()))
    minArr = [min(inputArr[0]+minArr[0], inputArr[0]+minArr[1]),
              min(inputArr[1]+minArr[0], inputArr[1]+minArr[1], inputArr[1]+minArr[2]),
              min(inputArr[2]+minArr[1], inputArr[2]+minArr[2])]
    maxArr = [max(inputArr[0]+maxArr[0], inputArr[0]+maxArr[1]),
              max(inputArr[1]+maxArr[0], inputArr[1]+maxArr[1], inputArr[1]+maxArr[2]),
              max(inputArr[2]+maxArr[1], inputArr[2]+maxArr[2])]
print(max(maxArr), min(minArr))