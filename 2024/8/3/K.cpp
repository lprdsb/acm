#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
#define tor(i,v,u) for(int i=head[u],v=to[i];i;i=nxt[i],v=to[i])
#define pi pair<int,int>
#define fi first
#define se second
#define mpi(x,y) make_pair(x,y)
using namespace std;
typedef long long ll;

const int N = 1e5 + 7;
int n, rt, q;
vector<int>G[N];
int f[N][19], dep[N];

#define ls(x) ch[x][0]
#define rs(x) ch[x][1]
struct SEG {
    static const int N = 1e5 + 7, M = 18;
    int rt[N], ch[N * M][2], siz[N * M], tot;
    void mdy(int &rt, int ori, int l, int r, int x, int val) {
        rt = ++tot;
        siz[rt] = siz[ori] + val;
        if(l == r)return;
        int mid = (l + r) >> 1;
        if(x <= mid) {
            rs(rt) = rs(ori), mdy(ls(rt), ls(ori), l, mid, x, val);
        }
        else ls(rt) = ls(ori), mdy(rs(rt), rs(ori), mid + 1, r, x, val);
    }
    int qry(int rt1, int rt2, int l, int r, int k) {
        if(l == r)return l;
        int mid = (l + r) >> 1;
        if(k <= siz[ls(rt2)] - siz[ls(rt1)])return qry(ls(rt1), ls(rt2), l, mid, k);
        else return qry(rs(rt1), rs(rt2), mid + 1, r, k - (siz[ls(rt2)] - siz[ls(rt1)]));
    }
    int qry(int rt1, int rt2, int rt3, int rt4, int l, int r, int k) {
        // cout << "//" << l << ' ' << r << ' ' << k << endl;
        // cout << "//" << siz[rt1] << ' ' << siz[rt2] << ' ' << siz[rt3] << " " << siz[rt4] << endl;
        if(l == r)return l;
        int mid = (l + r) >> 1;
        if(k <= siz[ls(rt2)] - siz[ls(rt1)] + siz[ls(rt4)] - siz[ls(rt3)])return qry(ls(rt1), ls(rt2), ls(rt3), ls(rt4), l, mid, k);
        else return qry(rs(rt1), rs(rt2), rs(rt3), rs(rt4), mid + 1, r, k - (siz[ls(rt2)] - siz[ls(rt1)] + siz[ls(rt4)] - siz[ls(rt3)]));
    }
    void prt(int k, int l, int r) {
        cout << "///" << l << " " << r << " " << siz[k] << endl;
        if(l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        prt(ls(k), l, mid);prt(rs(k), mid + 1, r);
    }
}S;

struct SEGG {
    static const int N = 2e5 + 7, M = 18;
    int rt[N], ch[N * M][2], siz[N * M], tot;
    void mdy(int &rt, int ori, int l, int r, int x, int val) {
        rt = ++tot;
        siz[rt] = siz[ori] + val;
        if(l == r)return;
        int mid = (l + r) >> 1;
        if(x <= mid) {
            rs(rt) = rs(ori), mdy(ls(rt), ls(ori), l, mid, x, val);
        }
        else ls(rt) = ls(ori), mdy(rs(rt), rs(ori), mid + 1, r, x, val);
    }
    pi qry(int rt, int l, int r, int k) {
        if(l == r) {
            return mpi(l, k);
        }
        int mid = (l + r) >> 1;
        if(k <= siz[ls(rt)])return qry(ls(rt), l, mid, k);
        else return qry(rs(rt), mid + 1, r, k - siz[ls(rt)]);
    }
    void prt(int k, int l, int r) {
        if(l == r) {
            cout << "///" << siz[k] << endl;
            return;
        }
        int mid = (l + r) >> 1;
        prt(ls(k), l, mid);prt(rs(k), mid + 1, r);
    }
}T;
#undef ls
#undef rs

int qry(int tar, int x) {
    fn(i, 18, 0) {
        if(dep[f[x][i]] > dep[tar])x = f[x][i];
    }
    return x;
}

int dfn[N], rfn[N], dfnidx, siz[N];

void dfs(int u, int fa) {
    siz[u] = 1;
    dfn[u] = ++dfnidx;
    S.mdy(S.rt[dfn[u]], S.rt[dfn[u] - 1], 1, n, u, 1);
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    fs(i, 1, 18)f[u][i] = f[f[u][i - 1]][i - 1];
    for(int v : G[u]) {
        if(v ^ fa)dfs(v, u), siz[u] += siz[v];
    }
    rfn[u] = dfnidx;
}

void dfs2(int u, int fa) {
    if(u != rt) {
        int hhh;
        T.mdy(hhh, T.rt[fa], 1, n, fa, -siz[u]);
        T.mdy(T.rt[u], hhh, 1, n, u, siz[u]);
    }
    else {
        T.mdy(T.rt[u], 0, 1, n, u, siz[u]);
    }
    for(int v : G[u]) {
        if(v ^ fa)dfs2(v, u);
    }
}

void solve() {
    scanf("%d%d", &n, &q);
    fs(i, 1, n) {
        int x;scanf("%d", &x);
        if(!x)rt = i;
        else G[x].emplace_back(i), G[i].emplace_back(x);
    }
    //dfs都是从rt下去dfs
    dfs(rt, 0);dfs2(rt, 0);
    //询问整数可以爆ll
    // fs(i, 1, n)cout << dfn[i] << ' ';
    // cout << endl;
    // fs(i, 1, n) {
    //     S.prt(S.rt[i], 1, n);
    //     cout << endl;
    // }
    while(q--) {
        ll num;scanf("%lld", &num);
        int x = (num - 1) / n + 1;
        int k = num - (ll)(x - 1) * n;
        // cout << "//" << x << " " << k << endl;
        auto [nd, rk] = T.qry(T.rt[x], 1, n, k);
        // T.prt(T.rt[x], 1, n);
        // cout << "//" << nd << ' ' << rk << endl;
        if(nd ^ x) {
            int son = qry(nd, x);
            // cout << "//" << son << endl;
            int y = S.qry(S.rt[dfn[nd] - 1], S.rt[dfn[son] - 1], S.rt[rfn[son]], S.rt[rfn[nd]], 1, n, rk);
            // cout << "//" << dfn[nd] << ' ' << rfn[nd] << " " << dfn[son] << " " << rfn[son] << endl;
            // cout << "//" << y << endl;
            printf("%lld\n", (ll)(x - 1) * n * n + (ll)(nd - 1) * n + (y - 1));
        }
        else {
            // cout << "//" << endl;
            int y = S.qry(S.rt[dfn[x] - 1], S.rt[rfn[x]], 1, n, rk);
            printf("%lld\n", (ll)(x - 1) * n * n + (ll)(x - 1) * n + (y - 1));
        }
    }
}

signed main() {
    solve();
}