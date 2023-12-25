
T = int(input())

def gcd(x, y):
    if y == 0:
        return x
    else:
        return gcd(y, x % y)
    
def exgcd(a, b, c):
    if(b == 0):
        return c // a, 0
    xx, yy = exgcd(b, a % b, c)
    x = yy
    y = xx - a // b * yy
    tem = x // b
    x -= b * tem
    y += a * tem
    return x, y

while(T):
    T -= 1
    x1, y1, x2, y2 = map(int, input().split())
    if x1 == x2:
        print(x1 + 1, 114514)
    else:
        kp = y1 - y2
        kq = x1 - x2
        bp = x1 * y2 - x2 * y1
        bq = x1 - x2
        gc = gcd(kp, kq)
        kp //= gc
        kq //= gc
        gc = gcd(bp, bq)
        bp //= gc
        bq //= gc
        k = (bp * kq // bq) * bq - bq
        if k + bq != bp * kq and abs(k + bq - bp * kq) < abs(k - bp * kq):
            k += bq
        if k + bq != bp * kq and abs(k + bq - bp * kq) < abs(k - bp * kq):
            k += bq
        k //= bq
        x, y = exgcd(kp, -kq, -k)
        print(x, y)

