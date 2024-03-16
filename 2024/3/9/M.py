import sys
n, k = map(int, input().split())
sys.set_int_max_str_digits(20000)
m = 10 ** k - 1

a = []
p = [998244353, 1000000007]
cnt = 0

for i in range(n):
    x = int(input()) % m
    if x == 0:
        cnt += 1
    a.append([x % p[0], x % p[1]])

ma = {}
# print(ma[1] is None)

for i in range(n):
    if ma.get(a[i][0]) == None:
        ma[a[i][0]] = {}
    ma[a[i][0]][a[i][1]] = i

res = cnt * (cnt - 1) * (cnt - 2) // 3 + cnt + cnt * (cnt - 1)
mm = [m % p[0], m % p[1]]
for i in range(n):
    for j in range(i, n):
        t0 = mm[0] - a[i][0] - a[j][0]
        while(t0 < 0):
            t0 += p[0]
        t1 = mm[1] - a[i][1] - a[j][1]
        while(t1 < 0):
            t1 += p[1]
        if ma.get(t0) != None and ma[t0].get(t1) != None and ma[t0][t1] >= j:
            res += 1


mm[0] *= 2
mm[1] *= 2
if mm[0] >= p[0]:
    mm[0] -= p[0]
if mm[1] >= p[1]:
    mm[1] -= p[1]
for i in range(n):
    for j in range(i, n):
        t0 = mm[0] - a[i][0] - a[j][0]
        while(t0 < 0):
            t0 += p[0]
        t1 = mm[1] - a[i][1] - a[j][1]
        while(t1 < 0):
            t1 += p[1]
        if ma.get(t0) != None and ma[t0].get(t1) != None and ma[t0][t1] >= j:
            res += 1
print(res)
