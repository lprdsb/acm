mn = {}
mx = {}
sum = {}
mx_sum = 0
ans = 1145141919810

if __name__ == '__main__':
    arr = input().split()
    for i in range(len(arr)):
        x = int(arr[i])
        if x in sum:
            sum[x] = sum[x] + 1
            mx[x] = i
            if sum[x] > mx_sum:
                mx_sum = sum[x]
        else:
            sum[x] = 1
            mn[x] = mx[x] = i
    for key,value in sum.items():
        # print(key, value)
        tem = mx[key] - mn[key] + 1
        if value == mx_sum and ans > tem:
            ans = tem
    print(ans)