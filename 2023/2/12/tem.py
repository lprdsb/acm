n = int(eval(input()))

def chk(x):
    if x < 0:
        x = -x
    while x:
        if x % 10 == 9:
            return 1
        x = int(x / 10)
    return 0

ans = n % 9
if ans == 0:
    if chk(n):
        print(n)
    else:
        print(9)
else:
    print(ans)