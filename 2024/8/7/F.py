

def sol(x):
    res = [x]
    k = 1
    if x % 2 == 1:
        y = (x - 1) // 2
        res.append(2 * y * x)
        res.append(2 * (y + 1) * x)
        res.append(2 * (y + 1))
        k = 2
        x = y + 1
    while x % 2 == 0:
        k *= 2
        x //= 2
    while x != 1:
        # print(x, k)
        if x % 4 == 1:
            y = (x - 1) // 4
            res.append(4 * y * (4 * y + 1) * k)
            res.append(4 * y * (4 * y - 1) * k)
            res.append(y * 4 * k)
            x = y
            k *= 4
        elif x % 4 == 3:
            y = (x - 3) // 4
            res.append((4 * y + 3) * (4 * y + 2) * k)
            res.append((4 * y + 3) * (4 * y + 4) * k)
            res.append((y + 1) * 4 * k)
            x = y + 1
            k *= 4
        while x % 2 == 0:
            k *= 2
            x //= 2
    if k != 4:
        while k != 4:
            res.append(3 * k)
            k //= 2
        res.append(3 * k)
        res.append(k)
    return res

if __name__ == '__main__':

    T = int(input())

    for _ in range(T):
        x, y = map(int, input().split(' '))
        as1 = sol(x)
        as2 = sol(y)
        # print(as1, as2)
        as1 += as2[-2::-1]
        # print(as2[-2::-1])
        assert len(as1) <= 150
        assert as1[0] == x and as1[-1] == y
        print(len(as1) - 1)
        pre = -1
        for p in as1:
            assert pre == -1 or p * pre % (p + pre) == 0
            print(p, end = ' ')
            pre = p
        print('')

'''
3
3 4
3 5
114514 191810
'''