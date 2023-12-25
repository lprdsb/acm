
def cycleVal(S, P, Q, R):
    S = S.replace('P', P)
    S = S.replace('Q', Q)
    S = S.replace('R', R)
    # print(S)
    return bool(eval(S))

S = input()
P = input()
Q = input()
R = input()
print(cycleVal(S, R, P, Q))