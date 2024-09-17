import math


def sq(x):
    res = 0
    for o in range(128, -1, -1):
        to = res + (2 ** o)
        if to * to <= x:
            res = to
    return res

def sol(n, R):
    tem = 10 ** (n // 2)
    x1, x2 = R // (tem), R % tem
    sqr = sq(x1)
    res = 0
    res = sqr * (sq(tem - 1) + 1)
    if(sqr * sqr != x1): res += sq(tem - 1) + 1
    else: res += sq(x2) + 1
    return res

# print(1000000 // 1000)
n = int(input())
L, R = map(int, input().split(' '))
print(sol(n, R) - sol(n, L - 1))
