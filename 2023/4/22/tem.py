n = int(input())

def get_val(n):
    if n <= 2:
        return 1
    return get_val(n - 1) + get_val(n - 2)

def get_list(n):
    '''
    ans = [0, 1, 1]
    for i in range(3, n + 1):
        ans.append(ans[i - 1] + ans[i - 2])
    return ans
    '''
    ans = [0]
    for i in range(1, n + 1):
        ans.append(get_val(i))
    return ans

fib = get_list(n)
for i in range(1, n + 1):
    print(fib[i], end = ' ')
    if i % 5 == 0:
        print('')
