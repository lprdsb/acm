T = int(input())


def tra(s: str):
    a = 0
    b = 0
    s = list(s)
    pw1 = 1
    pw2 = 1
    l = len(s)
    for i in range(l - 1, -1, -1):
        if (l - i) % 2 == 1:
            if int(s[i]) == 1:
                # print(f'asdasd{pw1}')
                a += pw1
            pw1 *= -2
        else:
            if int(s[i]) == 1:
                b += pw2
            pw2 *= -2
    return a, b

def itra(a, b):
    if a == 0 and b == 0:
        print("0")
        return
    res = []
    i = 0
    while a != 0 or b != 0:
        i += 1
        if i % 2 == 1:
            res.append(1 if a % 2 != 0 else 0)
            a //= 2
            a = -a
        else:
            res.append(1 if b % 2 != 0 else 0)
            b //= 2
            b = -b
    l = len(res)
    for i in range(l - 1, -1, -1):
        print(res[i], end='')
    print("")

# print(1 // -2)

for _ in range(T):
    a, b = input().split(' ')
    a1, b1 = tra(a)
    a2, b2 = tra(b)
    ra = a1 * a2 - 2 * b1 * b2
    rb = a1 * b2 + b1 * a2
    # print(ra, rb)
    itra(ra, rb)
    
