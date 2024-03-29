

n, m = map(int, input().split(' '))

ans = [0 for i in range(n + 1)]
st = [[],[]]
op = [0 for i in range(m + 1)]
pos = [0 for i in range(m + 1)]
op[0] = pos[0] = 1
m += 1

for i in range(1, m):
    op[i], pos[i] = map(int, input().split(' '))

m += 1
op.append(0)
pos.append(1)

m += 1
op.append(1)
pos.append(n)

for i in range(m):
    if op[i] == 0:
        while len(st[0]) and pos[st[0][-1]] <= pos[i]: st[0].pop()
        st[0].append(i)
    else:
        while len(st[1]) and pos[st[1][-1]] >= pos[i]: st[1].pop()
        st[1].append(i)

print(st[0])
print(st[1])

now = [0, 0]
opt = []
opt.append(1)

while now[0] < len(st[0]) and now[1] < len(st[1]):
    while now[0] < len(st[0]) and st[0][now[0]] <= st[1][now[1]]: now[0] += 1
    if now[0] == len(st[0]): break
    opt.append(pos[st[0][now[0]]])
    while now[1] < len(st[1]) and st[1][now[1]] <= st[0][now[0]]: now[1] += 1
    if now[1] == len(st[1]): break
    opt.append(pos[st[1][now[1]]])

# for i in opt:
#     print(i, end = 'asd')
# print('')

l = 1
r = n
mx = n
for i in range(len(opt)):
    if i % 2 == 0:
        for j in range(l, opt[i]):
            ans[l] = mx
            l += 1
            mx -= 1
            if l > r : break
    else:
        for j in  range(r, opt[i], -1):
            ans[r] = mx
            r -= 1
            mx -= 1
            if l > r: break
    if l > r: break

print(*ans[1:])

