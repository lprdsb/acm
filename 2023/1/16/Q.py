n = 0
a = [[0 for i in range(51)] for i in range(50)]
eps = 1e-6

def chk(x):
    return abs(x) == 0

def tra(x):
    if abs(x) < 0.005:
        return 0
    return x

def sol():
    for i in range(n):
        if(chk(a[i][i])):
            for j in range(i + 1, n, 1):
                if a[j][i] != 0:
                    for p in range(n + 1):
                        a[i][p], a[j][p] = a[j][p], a[i][p]
                    break
        if chk(a[i][i]):
            return 0
        for j in range(n):
            if(j == i):
                continue
            tem = a[j][i] / a[i][i]
            for p in range(i, n + 1, 1):
                a[j][p] = a[j][p] - tem * a[i][p]
        '''
        for j in range(n):
            for p in range(n + 1):
                print(a[j][p], end = ' ')
            print('')
        '''
    return 1

def main():
    global n, a
    n = int(input())
    for i in range(n):
        arr = input().split()
        for j in range(n + 1):
            a[i][j] = float(arr[j])
    if(sol() == 0):
        print("-1")
    else:
        for i in range(n):
            print("%.2f" % (tra(a[i][n] / a[i][i])), end = ' ')
    return 0

if __name__ == "__main__":
    main()