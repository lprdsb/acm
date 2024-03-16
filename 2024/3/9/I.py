
T = int(input())
n = 0
k = 0

def chk(a, b):
    aa = 1
    bb = 1
    for i in range(k):
        aa = aa * a
        bb = bb * b
        if bb - aa >= n:
            if bb - aa == n:
                return 1 if i == k - 1 else 2
            else:
                return 2
    return 0

for _ in range(T):
    n, k = map(int, input().split())
    res = 0
    for i in range(1, 1000001):
        if n % i == 0:
            l = 1
            r = 1000000
            while l < r:
                md = (l + r) // 2
                if chk(l, l + i):
                    r = md
                else:
                    l = md + 1
            if chk(l, l + i) == 1:
                res += 1
    print(res)