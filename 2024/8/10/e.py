n,k=map(int,input().split())
s=input()
t=input()
l=n
f=[[-1 for _ in range(2)] for _ in range(l)]
g=[[-1 for _ in range(2)] for _ in range(l)]

tmpb=0
tmpw=0
for i in range(l):
    if s[i]=='W' and t[i]=='B':
        tmpb=i
    if s[i]=='B' and t[i]=='W':
        tmpw=i
    f[i][0]=tmpb
    f[i][1]=tmpw

tmpb=l
tmpw=l

for i in range(l-1,-1,-1):
    if s[i]=='W' and t[i]=='W':
        tmpb=i
    if s[i]=='B' and t[i]=='B':
        tmpw=i
    g[i][0]=tmpb
    g[i][1]=tmpw

ans=0
lb=-1
lw=-1

for i in range(l):
    c=s[i]
    if lb>=i:
        c='B'
    elif lw>=i:
        c='W'
    if c==t[i]:
        continue
    ans+=1
    if t[i]=='B':
        r=min(i+k-1,l-1)
        r=min(r, g[i][0])
        lb=f[r][0]
    else:
        r=min(i+k-1,l-1)
        r=min(r,g[i][1])
        lw=f[r][1]

print(ans)