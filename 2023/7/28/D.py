t = int(input())
n = 0 
k = 0
def sol(p):
    if p == 1:
        return n
    tem = n
    res = 0
    while tem:
        res += tem % p
        tem //= p
    return res

lim = 10000

for _ in range(t):
    n, k = map(int, input().split(' '))
    ans = n
    for i in range(2, min(lim, k + 1)):
        ans = min(ans, sol(i))
    if k >= lim:
        len = 1
        while lim ** len < n:
            for i in range(1, ans):
                if i * lim ** len > n:
                    break
                l = int(pow(n / i, 1 / len))
                r = l * 2
                l //= 2
                while l < r:
                    mid = (l + r) // 2
                    if i * mid ** len > n:
                        r = mid
                    else:
                        l = mid + 1
                r = min(r, k)
                if i * l ** len > n:
                    l -= 1
                l = min(l, k)
                while l >= lim and i * l ** len + (ans - i) * l ** (len - 1) >= n:
                    ans = min(ans, sol(l))
                    l -= 1
            len += 1
    print(ans)

