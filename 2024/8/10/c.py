n,t=map(int,input().split())

h=[]

for i in range(n):
    h.append(int(input()))

sum=0
mx=0

for i in range(n):
    sum+=h[i]
    mx=max(mx,h[i])

    if sum>t:
        print(1)
    else:
        print((t-sum)//mx+2)