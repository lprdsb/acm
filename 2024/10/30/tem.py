import heapq

n, m, s, t = map(int, input().split(' '))

ch = [[] for i in range(n + 5)]

for i in range(m):
    u, v, w = map(int, input().split(' '))
    ch[u].append((v, w))
    ch[v].append((u, w))

dis = [0x3f3f3f3f for i in range(n + 5)]
pre = [0 for i in range(n + 5)]

dis[s] = 0

q = [(0, s)]

heapq.heapify(q)

while len(q):
    d, u = heapq.heappop(q)
    for v, w in ch[u]:
        if dis[v] > dis[u] + w:
            dis[v] = dis[u] + w
            pre[v] = u
            heapq.heappush(q, (dis[v], v))

print(dis[t])
ans = []
while t:
    ans.append(t)
    t = pre[t]

ans.reverse()
for u in ans:
    print(u, end = ' ')