n, m = map(int, input().split(' '))

ma = [[0 for i in range(n)] for j in range(n)]

for i in range(m):
    u, v = map(int, input().split(' '))
    ma[u - 1][v - 1] = 1
    # print(u, v, 'asd')

for k in range(n):
    for i in range(n):
        for j in range(n):
            ma[i][j] |= ma[i][k] & ma[k][j]



for i in range(n):
    for j in range(n):
        if ma[i][j]:
            print(i + 1, j + 1)