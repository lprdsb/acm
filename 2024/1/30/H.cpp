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

#define maxn 100000
#define md (l + r >> 1)
#define ls (rt << 1)
#define rs (rt << 1 | 1)

int n, sum[4 * maxn + 5], b[maxn + 5], cnt = 0;
LL poi[4 * maxn + 5][5];
struct Node {
    int ty, x;
} opt[maxn + 5];

void mdy(int rt, int l, int r, int x, int y) {
    if(l == r) {
        sum[rt] += y;
        if(y == -1) {
            For(o, 0, 4) poi[rt][o] = 0;
        }
        else poi[rt][0] = b[l];
        return;
    }
    if(x <= md) mdy(ls, l, md, x, y);
    else mdy(rs, md + 1, r, x, y);
    sum[rt] = (sum[ls] + sum[rs]) % 5;
    For(o, 0, 4) poi[rt][o] = poi[ls][o] + poi[rs][(o - sum[ls] + 5) % 5];
}
char s[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    read(n);
    For(i, 1, n) {
        scanf("%s", s + 1);
        if(s[1] == 'a') opt[i].ty = 1;
        if(s[1] == 'd') opt[i].ty = -1;
        if(s[1] == 's') opt[i].ty = 2;
        else read(opt[i].x), b[++cnt] = opt[i].x;
    }
    sort(b + 1, b + cnt + 1);
    cnt = unique(b + 1, b + cnt + 1) - b - 1;
    For(i, 1, n) if(opt[i].ty != 2) opt[i].x = lower_bound(b + 1, b + cnt + 1, opt[i].x) - b;
    For(i, 1, n) {
        if(opt[i].ty != 2) mdy(1, 1, cnt, opt[i].x, opt[i].ty);
        else printf("%lld\n", poi[1][2]);
    }
    return 0;
}
