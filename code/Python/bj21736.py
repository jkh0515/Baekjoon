#21736 헌내기는 친구가 필요해 - Python 3
#메모리 : 55744KB / 시간 : 864ms
#2025년 3월 11일 00:41:32

n, m = map(int, input().split())
li, x, y, q, r, dp = [], 0, 0, [], 0, [[0 for _ in range(m)] for _ in range(n)]
tx, ty = [1, -1, 0, 0], [0, 0, 1, -1]
for i in range(n) :
    li.append(input())
    if "I" in li[-1] :
        x = i
        y = li[-1].find("I")
        q.append([x, y])
while len(q) > 0 :
    _x, _y = q.pop()
    for i in range(4) :
        x = _x + tx[i]
        y = _y + ty[i]
        if x < 0 or x >= n or y < 0 or y >= m : continue
        if li[x][y] == "X" or dp[x][y] != 0 : continue
        dp[x][y] = 1
        if li[x][y] == "P" : r += 1
        q.append([x, y])
print(r) if r != 0 else print("TT")