l,k=map(int,input().split())

f=[[0 for _ in range(2)]for _ in range(l+1) ]

f[0][0]=1

for i in range(1, l+1):
    f[i][0]+=f[i-1][1]
    f[i][1]+=f[i-1][0]
    if i>=k:
        f[i][1]+=f[i-k][0]

ans=0

for i in range(1, l+1):
    ans+=f[i][1]

print(ans)