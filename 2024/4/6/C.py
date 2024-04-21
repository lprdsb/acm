
def get_num(x, y, m):
    a = []
    while x:
        a.append(x % m)
        x //= m
    return a[-y]
        

def fun():
    n, m = map(int, input().split(' '))
    cnt = [m ** i for i in range(80)]
    for i in range(60, 0, -1): 
        cnt[i] -= cnt[i - 1]
        cnt[i] *= i
    for i in range(1, 60, 1):
        if n > cnt[i]:
            n -= cnt[i]
        else:
            # print(m ** (i - 1) + n // i, (n - 1) % i + 1)
            return get_num(m ** (i - 1) + (n - 1) // i, (n - 1) % i + 1, m)


T = int(input())

for _ in range(T):
    print(fun())