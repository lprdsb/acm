n = input()
arr = input().split()
pre = 0
ans = 0
now = 0
for val in arr:
    val = int(val)
    if val - pre > 0:
        now = now + 1
        if now > ans:
            ans = now
    else:
        now = 1
    pre = val
print(ans)
