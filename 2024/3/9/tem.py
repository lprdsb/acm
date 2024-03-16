def replace(s): #replace ->
    while 666:
        idx = s.find('->')
        if idx == -1:
            break
        s = s[0:idx] + ') or' + s[idx + 2:]
        idx -= 1
        cnt = 0
        while 666:
            if s[idx] == ')':
                cnt += 1
            if s[idx] == '(':
                cnt -= 1
                if cnt == -1:
                    s = s[0:idx + 1] + '(not ' + s[idx + 1:]
                    break
            idx -= 1
    return s

def trans(s):
    ma = {
        '~':'not',
        '^':'and',
        'v':'or',
        '<->':'=='
    }
    for k, v in ma.items():
        s = s.replace(k, v)
    s = replace(s)
    return s
