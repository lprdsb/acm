
def chk():
    arr = input()
    a = []
    for c in arr:
        if c == '(' or c == '[' or c == '{':
            a.append(c)
        elif c == ')':
            if len(a) and a[len(a) - 1] == '(':
                a.pop()
            else:
                return 0
        elif c == ']':
            if len(a) and a[len(a) - 1] == '[':
                a.pop()
            else:
                return 0
        elif c == '}':
            if len(a) and a[len(a) - 1] == '{':
                a.pop()
            else:
                return 0
    return len(a) == 0


if __name__ == '__main__':
    if chk() == 1:
        print('YES')
    else:
        print('NO')