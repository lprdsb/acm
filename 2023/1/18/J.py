from decimal import Decimal as DD

ans = 0
a = []
n = int(input())
ans = 0

arr = input().split()
for i in range(n):
    a.append(DD(arr[i]))
    if i == 0:
        ans = a[i]
        continue
    mx = ans
    tem = ans + a[i]
    if tem > mx:
        mx = tem
    tem = ans * a[i]
    if tem > mx:
        mx = tem
    if a[i] != 0:
        tem = ans / a[i]
        if tem > mx:
            mx = tem
    ans = mx
print(DD(ans).quantize(DD('0.001'), rounding = 'ROUND_HALF_UP'))