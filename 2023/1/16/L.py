arr = input().split()
n = int(arr[0])
m = int(arr[1])

ok = [1 for i in range(n)]

ans = n
now = 0
for i in range(n - 1):
    # print('')
    # for j in range(n):
    #     print(ok[j], end = ' ')
    # print('')
    for j in range(m):
        while ok[now] == 0:
            now = now + 1
            if now == n:
                now = 0
        if j == m - 1:
            ok[now] = 0
            if now == 0:
                ans = i + 1
        now = now + 1
        if now == n:
            now = 0
print(ans, end = ' ')
for i in range(n):
    if ok[i]:
        print(i + 1)
