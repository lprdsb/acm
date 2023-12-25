import sys

ma = [0 for i in range(512 * 512)]

f = [-1 for i in range(512)]

if __name__ == "__main__":
    arr = input()
    arr = arr.split()
    n = int(arr[0])
    m = int(arr[1])
    s = int(arr[2])
    t = int(arr[3])
    s = s - 1
    t = t - 1

    for i in range(m):
        arr = input()
        arr = arr.split()
        u = int(arr[0])
        v = int(arr[1])
        u = u - 1
        v = v - 1
        if u > v: 
            tem = u
            u = v
            v = tem
        ma[u * n + v] = 1
    f[s] = 0
    for i in range(s + 1, t + 1, 1):
        mn = 600
        for j in range(s, i, 1):
            if f[j] != -1 and ma[j * n + i] == 1 and f[j] < mn:
                mn = f[j]
        if mn != 600:
            f[i] = mn + 1
    print(f[t])