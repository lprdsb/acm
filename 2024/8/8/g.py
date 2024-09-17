n=int(input())
b=list(map(int ,input().split()))
f=[[[0 for _ in range(3)] for _ in range(3)]  for _ in range(n+1)]

cur=1

if b[0]==-1:
    for i in range(0, 3):
        f[0][i][(i+1)%3]=1
    cur*=3
else:
    f[0][b[0]][(b[0]+1)%3]=1

for i in range(1,n):
    for j in range(0, 3):
        if b[i]!=-1 and b[i]!=j:
            continue
        for k in range(0, 3):
            if k==(j+2)%3:
                continue
            for l in range(0, 3):
                if b[i-1]!=-1 and b[i-1]!=l:
                    continue
                tmp = 0
                for m in range(0, 3):
                    if m==(l+2)%3 or m==k:
                        continue
                    print(i,j,k,l,m)
                    tmp=max(tmp, f[i-1][l][m])
                f[i][j][k]+=tmp
            if k==(j+1)%3:
                f[i][j][k]+=cur
            print(i,j,k,f[i][j][k])
    if b[i]==-1:
        cur*=3

ans=0
for i in range(0, 3):
    tmp = 0
    for j in range(0, 3):
        tmp=max(tmp, f[n-1][i][j])
    ans+=tmp

print(ans%998244353)