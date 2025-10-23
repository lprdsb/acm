# a = '+'

# print('123'.count('2',0,2))

# pre = 0

# for i in range(1000):
#     a = a.replace('+', '+@')
#     a = a.replace('-', '+')
#     a = a.replace('@', '-')
#     a = a[0:i + 1]
#     now = a.count('+', 0, i)
#     print(now, end = '\n')
    # print(a[-1])
    # pre = now
# p = 0
# while p < len(a):
#     print(a[p:p + 89])
#     p += 89


bas = 60
pw = 2 ** (bas // 2)
sq5 = 5 * (2 ** (2 * bas))

now = 0

for i in range(0, 1000):
    to = now + (2 ** (999 - i))
    if to * to <= sq5:
       now = to

sq5 = now
tmp = (sq5 - (2 ** bas)) // 2
print(tmp // pw, tmp % pw)
print(tmp * 998244354 // (2 ** bas))

import math
# print((math.sqrt(5) - 1) / 2 * (10 **))
