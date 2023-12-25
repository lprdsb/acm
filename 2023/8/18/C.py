n = int(input())
k = int(input())

d = []

res = 0


def gcd(a, b):
    if b != 0:
        return gcd(b, a % b)
    else:
        return a

for i in range(100):
    d.append(10 ** i)

for i in range(1, 101):
    for j in range(1, 100 - i + 1):
        # if i == 4 and j == 2:
        #     print(p, q)
        p = d[i] - k
        q = k * d[j] - 1
        gc = gcd(p, q)
        p //= gc
        q //= gc
        for o in range(max(1, d[j - 1] // q - 10), d[j] // q + 10, 1):
            b = o * q
            if b >= d[j - 1] and b < d[j]:
                a = o * p
                if a >= d[i - 1] and a < d[i]:
                    if a * d[j] + b <= n:
                        res = max(res, a * d[j] + b)
print(res)
                
