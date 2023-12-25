n = int(input())
t = []
a = []
pos = []
arr = input().split()
for val in arr:
    t.append(int(val))
arr = input().split()
for val in arr:
    a.append(int(val))
for i in range(n):
    pos.append(i)
pos = sorted(pos, key = lambda x : t[x] / a[x])
sum = 0
ans = 0
for i in range(n):
    ans = ans + sum * a[pos[i]]
    sum = sum + t[pos[i]]
print(ans)