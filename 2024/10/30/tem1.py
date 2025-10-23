import queue

n, m, s, t = map(int, input().split(' '))

ch = [[[] for i in range(n + 5)] for o in range(2)]
d = [[0 for i in range(n + 5)] for o in range(2)]

for i in range(m):
    u, v, w = map(int, input().split(' '))
    ch[0][u].append((v, w))
    ch[1][v].append((u, w))
    d[0][v] += 1
    d[1][u] += 1

dis = [[0 for i in range(n + 5)] for o in range(2)]

q = queue.Queue(1005)

# for i in range(1, n + 1):
#     if i != s and d[0][i] == 0:
#         while 666:
#             i += 1
# for i in range(1, n + 1):
#     if i != t and d[1][i] == 0:
#         while 666:
#             i += 1

q.put(s)
while not q.empty():
    u = q.get()
    tt = u
    for v, w in ch[0][u]:
        if dis[0][v] < dis[0][u] + w:
            dis[0][v] = dis[0][u] + w
        d[0][v] -= 1
        if d[0][v] == 0:
            q.put(v)

dis[1] = [0x3f3f3f3f for i in range(n + 5)]
dis[1][tt] = dis[0][tt]
q.put(tt)
while not q.empty():
    u = q.get()
    for v, w in ch[1][u]:
        if dis[1][v] > dis[1][u] - w:
            dis[1][v] = dis[1][u] - w
        d[1][v] -= 1
        if d[1][v] == 0:
            q.put(v)

# if dis[1][t] != dis[0][t]:
#     while 666:
#         t += 1

res = dis[0][t]
print(res)
for i in range(1, n + 1):
    print(dis[0][i], dis[1][i], dis[1][i] - dis[0][i])

ans = []
now = []
def dfs(u):
    if u == t:
        ans.append(now.copy())
        return
    for v, w in ch[0][u]:
        if dis[0][v] == dis[1][v] and dis[0][u] + w == dis[0][v]:
            now.append(v)
            dfs(v)
            now.pop()

now = [s]
dfs(s)
# print(ans)

def cmp(x, y):
    if len(x) != len(y):
        return len(x) - len(y)
    for i in range(len(x)):
        if(x[i] != y[i]):
            return x[i] - y[i]
    return 0

def cmp_to_key(mycmp):
    'Convert a cmp= function into a key= function'
    class K(object):
        def __init__(self, obj, *args):
            self.obj = obj
        def __lt__(self, other):
            return mycmp(self.obj, other.obj) < 0
        def __gt__(self, other):
            return mycmp(self.obj, other.obj) > 0
        def __eq__(self, other):
            return mycmp(self.obj, other.obj) == 0
        def __le__(self, other):
            return mycmp(self.obj, other.obj) <= 0
        def __ge__(self, other):
            return mycmp(self.obj, other.obj) >= 0
        def __ne__(self, other):
            return mycmp(self.obj, other.obj) != 0
    return K

ans = sorted(ans, key = cmp_to_key(cmp))
pre = []
for path in ans:
    if cmp(path, pre) == 0:
        continue
    print(' '.join(map(str, path)))
    pre = path
