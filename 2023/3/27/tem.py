
def check(S, P, Q):
    S = S.replace('P', str(P))
    S = S.replace('Q', str(Q))
    return bool(eval(S))

def func(S):
    if check(S, 0, 0) and check(S, 0, 1) and check(S, 1, 0) and check(S, 1, 1):
        return True
    return False

s1 = '(not ' + input() + ') or ((not P) or Q)' 
print(func(s1))