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

#define maxn 1000000
int T, n;
int ch[maxn + 5][26], sum[maxn + 5], tot, a[maxn + 5], to[maxn + 5][26], sz[maxn + 5];
char s[maxn + 5];

int cnt = 0;
void dfs(int u) {
    sz[u] = a[u];
    cnt += a[u];
    sum[u] = cnt;
    to[u][0] = u;
    For(o, 0, 25) {
        if(o) to[u][o] = to[u][o - 1];
        if(ch[u][o]) {
            dfs(ch[u][o]);
            sz[u] += sz[ch[u][o]];
            to[u][o] = to[ch[u][o]][25];
        }
    }
}

LL dfs1(int rt, int u1, int u2) {
    LL res = 0;
    if(u1 == rt) res += 1ll * a[u1] * (a[u1] - 1) / 2 * (sum[u1] - a[u1]) + 1ll * a[u1] * (a[u1] - 1) * (a[u1] - 2) / 6;
    else if(a[u1]) {
        res += 1ll * a[rt] * a[u1] * max(0, sum[rt] - a[rt] - sum[u2]);
        if(sum[rt] >= sum[u2]) res += 1ll * a[u1] * a[rt] * (a[rt] - 1) / 2;
    }
    For(o, 0, 25) if(ch[u1][o]) {
        if(ch[u2][o]) res += dfs1(rt, ch[u1][o], ch[u2][o]);
        else {
            res += 1ll * a[rt] * (sz[u1] - a[u1]) * max(0, sum[rt] - a[rt] - sum[to[u2][o]]);
            if(sum[rt] >= sum[to[u2][o]]) res += 1ll * (sz[u1] - a[u1]) * a[rt] * (a[rt] - 1) / 2;
        }
    }
    return res;
}

void mian() {
    tot = 1;
    read(n);
    For(i, 1, n) {
        scanf("%s", s + 1);
        int now = 1, len = strlen(s + 1);
        For(j, 1, len) {
            if(!ch[now][s[j] - 'a']) ch[now][s[j] - 'a'] = ++tot;
            now = ch[now][s[j] - 'a'];
        }
        a[now]++;
    }
    cnt = 0;
    dfs(1);
    LL res = 0;
    For(i, 1, tot) if(a[i]) res += dfs1(i, i, 1);
    printf("%lld\n", res);
}

int main() {
    freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, tot) {
            sum[i] = a[i] = sz[i] = 0;
            For(o, 0, 25) ch[i][o] = to[i][o] = 0;
        }
    }
}
