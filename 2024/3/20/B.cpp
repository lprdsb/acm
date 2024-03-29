#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define LL long long
#define DD double
#define LD long double
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define eps 1e-12
using namespace std;

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int a[20];
char s[20];

LL f[1 << 17][20][2];
LL dfs(int sta, int pos, int fl) {
    if(pos == 18) return 1;
    if(f[sta][pos][fl] != -1) return f[sta][pos][fl];
    LL res = 0, up = fl ? a[pos] : 16;
    For(o, 0, up) if(!((sta >> o) & 1)) res += dfs(sta | (1 << o), pos + 1, fl & (o == up));
    return f[sta][pos][fl] = res;
}

int main() {
    //freopen("in", "r", stdin);
    LL tem = 254081962595832ll - 4542892071975ll;
    LL fac = 1;
    For(i, 1, 17) fac *= i;
    printf("%lld\n", min(tem, fac - tem));
    memset(f, -1, sizeof f);
    scanf("%s", s + 1);
    For(i, 1, 17) {
        if(s[i] <= 'm') a[i] = s[i] - 'a';
        else a[i] = s[i] - 'a' - 1;
    }
    printf("%lld", dfs(0, 1, 1));
}
/*
aejcldbhpiogfqnkr
4542892071975
ncfjboqiealhkrpgd
254081962595832

420973902368

106148357572143
*/