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

#define maxn 400000
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define md (l + r >> 1)

int T, n, a[maxn + 5], st[maxn + 5], tp = 0, ch[maxn + 5][2];
int dep[maxn + 5], to[maxn + 5], dfn[maxn + 5], sz[maxn + 5], tim = 0, id[maxn + 5];
int mx[4 * maxn + 5];
void build(int rt, int l, int r) {
    if(l == r) {
        mx[rt] = dep[id[l]];
        return;
    }
    build(ls, l, md); build(rs, md + 1, r);
    mx[rt] = max(mx[ls], mx[rs]);
}
int que(int rt, int l, int r, int ql, int qr) {
    if(ql > qr) return 0;
    if(ql <= l && qr >= r) return mx[rt];
    int res = 0;
    if(ql <= md) res = max(res, que(ls, l, md, ql, qr));
    if(qr > md) res = max(res, que(rs, md + 1, r, ql, qr));
    return res;
}
int ty[maxn + 5];
int mxdp[maxn + 5][2], res = 0;
void dfs(int u, int pre) {
    // cout << a[u] << endl;
    mxdp[u][0] = dep[u];
    mxdp[u][1] = 0;
    ty[u] = u != ch[pre][0];
    dfn[u] = ++tim; id[tim] = u;
    sz[u] = 1;
    For(o, 0, 1) if(ch[u][o]) {
        int v = ch[u][o];
        if(o == ty[u]) to[v] = to[u];
        else to[v] = pre;
        dep[v] = dep[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
        int tem = mxdp[v][0];
        For(o1, 0, 1) if(tem > mxdp[u][o1]) swap(tem, mxdp[u][o1]);
    }
}
void dfs1(int u) {
    For(o, 0, 1) if(ch[u][o]) {
        int v = ch[u][o];
        dfs1(v);
    }
    For(o, 0, 1) if(ch[u][o]) {
        int v = ch[u][o];
        if(to[u] && to[v]) res = max(res, mxdp[u][mxdp[v][0] == mxdp[u][0]] - dep[u] + mxdp[v][0] - dep[v] + dep[to[v]] - dep[to[u]] + 2);
    }
    res = max(res, mxdp[u][0] + mxdp[u][1] - dep[u] * ((mxdp[u][0] != 0) + (mxdp[u][1] != 0)));
    if(to[u]) {
        res = max(res, mxdp[u][0] - dep[u] + 1 + max(que(1, 1, n, dfn[to[u]], dfn[u] - 1), que(1, 1, n, dfn[u] + sz[u], dfn[to[u]] + sz[to[u]] - 1)) - dep[to[u]]);
        if(to[ch[to[u]][!ty[u]]]) {
            res = max(res, mxdp[u][0] - dep[u] + 1 + dep[to[u]] - dep[to[ch[to[u]][!ty[u]]]] + mxdp[ch[to[u]][!ty[u]]][mxdp[ch[to[u]][!ty[u]]][0] == mxdp[u][0]] - dep[ch[to[u]][!ty[u]]] + 1);
            // if(res == 5) cout << mxdp[u][0] - dep[u] + 1 + dep[to[u]] - dep[to[ch[to[u]][!ty[u]]]] << endl;
        }
    }
}

char s[maxn + 5];
void mian() {
    read(n);
    a[0] = inf;
    For(i, 1, n) read(a[i]);
    scanf("%s", s + 1);
    tp = 0;
    For(i, 1, n) {
        while(tp && a[i] > a[st[tp]]) {
            tp--;
            if(a[i] > a[st[tp]]) ch[st[tp]][1] = st[tp + 1];
            else ch[i][0] = st[tp + 1];
        }
        st[++tp] = i;
    }
    while(tp > 1) ch[st[tp - 1]][1] = st[tp], tp--;
    int rt = st[1]; dep[rt] = 0; tim = 0; to[rt] = 0;
    dfs(rt, 0);
    // For(i, 1, n) cout << a[i] << " " << a[to[i]] << endl;
    build(1, 1, n);
    res = 0;
    dfs1(rt);
    printf("%d\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    For(_, 1, T) {
        mian();
        For(i, 1, n) For(o, 0, 1) ch[i][o] = 0;
        // if(T == 100 && _ == 6) {
        //     cout << "asd" << endl;
        //     cout << n << endl;
        //     For(i, 1, n) cout << a[i] << " "; cout << endl;
        // }
    }
}
