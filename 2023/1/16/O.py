

if __name__ == '__main__':
    arr = input().split()
    n = int(arr[0])
    s = int(arr[1])
    k1 = -int(arr[2])
    k2 = -int(arr[3])
    a = []
    ans1 = s
    ans2 = 0
    ok = 0
    for i in range(n):
        if i % 7 == 0:
            ok = 0
            a.clear()
        x = k1
        arr = input()
        tem = 0
        tem1 = 1
        for c in arr:
            if c == ' ':
                x = x + tem1 * tem
                tem = 0
                tem1 = 1
            elif c == '-':
                tem1 = -1
            elif c >= '0' and c <= '9':
                tem = tem * 10 + int(c)
        x = x + tem1 * tem
        a.append(k2 - x)
        if(x > k2):
            ans1 = ans1 + x
            ans2 = ans2 + 1 
        else:
            ok = 1
            ans1 = ans1 + k2
        if i % 7 == 6 and ok != 1:
            mx = a[6]
            for j in range(6):
                if a[j] > mx:
                    mx = a[j]
            ans1 = ans1 + mx
            ans2 = ans2 - 1
    print(ans2, ans1)