import math
import decimal

a = decimal.Decimal('365365365365')
b = decimal.Decimal('365365365365365365365365')
c = decimal.Decimal('1')
e = decimal.Decimal('2.718281828459045235360287471352')

tmp = -a * (a - 1) / b / 2

print(e ** tmp)

# print(math.exp(t-1-t * math.log(t)))