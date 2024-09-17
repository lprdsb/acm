class Frac:
    def __init__(self, p, q):
        self.p = p
        self.q = q

def gcd(x, y):
    if y == 0: return x
    return gcd(y, x % y)

def norm(x):
    gc = gcd(x.p, x.q)
    x.p //= gc
    x.q //= gc
    return x

def add(x, y):
    res = Frac(x.p * y.p, 0)
    res.q += x.q * y.p + x.p * y.q
    return norm(res)

def mul(x, y):
    res = Frac(x.p * y.p, x.q * y.q)
    return norm(res)

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        c, a, b = map(int, input().split(' '))
        a = b - a
        aa = Frac(b - a, b)
        bb = Frac(b - a, -a)
        cc = Frac(b - a, -b)
        f = [Frac(1, 0), Frac(1, 1)]
        g = [Frac(1, 0), Frac(1, 0)]
        h = [0 for i in range(2 * c)]
        for i in range(2, 2 * c + 1):
            f.append(add(mul(aa, f[i - 1]), mul(bb, f[i - 2])))
            g.append(add(mul(aa, g[i - 1]), mul(bb, g[i - 2])))
            g[-1] = add(g[-1], cc)
            norm(g[-1])
            if i % 2 == 0:
                tem = g[-1]
                tem.q = -tem.q
                tem.p *= f[-1].q
                tem.q *= f[-1].p
                tem = norm(tem)
                h[i // 2] = add(mul(f[i // 2], tem), g[i // 2])
        for item in h:
            if isinstance(item, Frac): print(item.q, item.p)

