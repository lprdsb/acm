class Node:
    def __init__(self, _t, _a):
        self.t = _t
        self.a = _a

node = []
t = []
a = []
f = [[-1 for i in range(5000005)] for i in range(2)]

def chkmn(a, b):
    if a == -1 or a > b:
        return b
    return a

if __name__ == "__main__":
    n = int(input())
    arr = input()
    t = [int(i) for i in arr.split()]
    arr = input()
    a = [int(i) for i in arr.split()]
    for i in range(n):
        node.append(Node(t[i], a[i]))
    node = sorted(node, key = lambda node: node.t / node.a)
    sum = 0
    f[0][0] = 0
    ans = -1
    for i in range(n):
        po = i & 1
        o = 1 - po
        tem = sum + node[i].t + 1
        for j in range(tem):
            f[o][j] = -1
            if f[po][j] != -1:
                f[o][j] = f[po][j] + (sum - j) * node[i].a
            if j >= node[i].t and f[po][j - node[i].t] != -1:
                f[o][j] = chkmn(f[o][j], f[po][j - node[i].t] + (j - node[i].t) * node[i].a)
        sum = sum + node[i].t 
    for i in range(sum + 1):
        if f[o][i] != -1:
            ans = chkmn(ans, f[o][i])
    print(ans)
