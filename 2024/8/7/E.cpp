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
int tot = 0;
struct Tree {
    int n;
    vector<vector<int> > ch;
    Tree() {
        n = 0;
        ch.resize(1);
    }
    Tree(int _n) {
        n = _n;
        ch.resize(n + 1);
    }
    int get_new(int id) {
        ch.pb({});
        return ++n;
    }
} tr[maxn + 5];

int n, k, c[maxn + 5];

int dfn[maxn + 5], stk[2 * maxn + 5], tp = 0, dep[maxn + 5];
void dfs(Tree &T, int u, int pre) {
    dfn[u] = ++tp;
    stk[tp] = u;
    dep[u] = dep[pre] + 1;
    for(auto v : T.ch[u]) if(v != pre) {
        dfs(T, v, u);
        stk[++tp] = u;
    }
}

namespace ST {
    int n, mn[2][2 * maxn + 5][30];
    void init() {
        n = tp;
        For(o, 0, 30) {
            For(i, 1, tp) {
                mn[0][i][0] = mn[1][i][0] = stk[i];
                if(o) {
                    mn[0][i][o] = mn[0][i][o - 1]; mn[1][i][o] = mn[1][i][o - 1];
                    int to = i - (1 << (o - 1));
                    if(to >= 1 && dep[mn[0][to][o - 1]] < dep[mn[0][i][o]]) mn[0][i][o] = mn[0][to][o - 1];
                    to = i + (1 << (o - 1));
                    if(to <= n && dep[mn[1][to][o - 1]] < dep[mn[1][i][o]]) mn[1][i][o] = mn[1][to][o - 1];
                }
            }
        }
    }
    int que(int l, int r) {
        int o = 0, L = 1;
        while((L << 1) <= r - l + 1) L <<= 1, o++;
        int res = mn[0][r][o];
        if(dep[mn[1][l][o]] < dep[res]) res = mn[1][l][o];
        return res;
    }
}

int lca(int u, int v) {
    if(dfn[u] > dfn[v]) swap(u, v);
    return ST::que(dfn[u], dfn[v]);
}

int sz[maxn + 5], Hs[maxn + 5], lsz[maxn + 5];
void dfs1(Tree &T, int u, int pre) {
    sz[u] = 1;
    Hs[u] = 0;
    for(auto v : T.ch[u]) if(u != pre) {
        dfs1(T, v, u);
        sz[u] += sz[v];
        if(sz[Hs[u]] < sz[v]) Hs[u] = v;
    }
    lsz[u] = sz[u] - sz[Hs[u]];
}
LL sum[maxn + 5];
vector<int> F[maxn + 5], G[maxn + 5], H[maxn + 5], S[maxn + 5];

#define mod 998244353
namespace NTT {
    int a[4 * maxn + 5], b[4 * maxn + 5];
    int fp(int x, int y) {
        int asi = 1;
        while(y) {
            if(y & 1) asi = 1ll * asi * x % mod;
            x = 1ll * x * x % mod;
            y >>= 1;
        }
        return asi;
    }
    int g = 3, ig = fp(g, mod - 2);

    int lim, lim_inv, to[4 * maxn + 5];
    void ntt_pre(int x) {
        int l = 0; lim = 1;
        while(lim < x) lim <<= 1, l++;
        For(i, 0, lim - 1) to[i] = (to[i >> 1] >> 1) + ((i & 1) << (l - 1));
        lim_inv = fp(lim, mod - 2);
    }

    void ntt(int *x, int gi) {
        For(i, 0, lim - 1) if(i < to[i]) swap(x[i], x[to[i]]);
        for(int i = 2; i <= lim; i <<= 1) {
            int w = fp(gi, (mod - 1) / i), ii = i >> 1;
            for(int j = 0; j < lim; j += i) {
                int wi = 1;
                For(p, j, j + ii - 1) {
                    int tem1 = x[p], tem2 = 1ll * wi * x[p + ii] % mod;
                    x[p] = (tem1 + tem2) % mod;
                    x[p + ii] = (tem1 - tem2 + mod) % mod;
                    wi = 1ll * wi * w % mod;
                }
            }
        }
        if(gi == ig) {
            For(i, 0, lim - 1) a[i] = 1ll * a[i] * lim_inv % mod;
        }
    }
}

#define COPY(A, V) {For(i, 0, V.size() - 1) A[i] = V[i]; For(i, V.size(), lim - 1) A[i] = 0;}
#define ICOPY(V, A) {For(i, 0, V.size() - 1) V[i] = A[i];}
int sol_tmp[2][4 * maxn + 5], ok[maxn + 5];
void sol(int rt, vector<int> &vec) {
    int lim, up = 0;
    for(auto v : vec) up += max(F[v].size(), G[v].size()) - 1;
    NTT::ntt_pre(up + 1); lim = NTT::lim;
    int fl = 0;
    for(auto v : vec) {
        COPY(NTT::a, F[v]); NTT::ntt(NTT::a, NTT::g);
        COPY(NTT::b, G[v]); NTT::ntt(NTT::b, NTT::g);

        For(i, 0, lim - 1) {
            if(fl) {
                sol_tmp[0][i] = 1ll * sol_tmp[0][i] * NTT::a[i] % mod;
                sol_tmp[1][i] = 1ll * sol_tmp[1][i] * ((1ll * NTT::b[i] + NTT::a[i] * ok[v]) % mod) % mod;
            }
            else {
                sol_tmp[0][i] = NTT::a[i];
                sol_tmp[1][i] = (1ll * NTT::b[i] + NTT::a[i] * ok[v]) % mod;
            }
        }

        fl = 1;
    }

    For(i, 0, lim - 1) NTT::a[i] = sol_tmp[0][i], NTT::b[i] = sol_tmp[1][i];
    NTT::ntt(NTT::a, NTT::ig); NTT::ntt(NTT::b, NTT::ig);
    H[rt].resize(up + 1); S[rt].resize(up + 1);
    ICOPY(H[rt], NTT::a); ICOPY(F[rt], NTT::b);
}


void mul(cst vector<int> &a, cst vector<int> &b, vector<int> &c) {
    int lim = 0, up = a.size() - 1 + b.size() - 1;
    NTT::ntt_pre(up + 1); lim = NTT::lim;
    COPY(NTT::a, a); COPY(NTT::b, b);
    NTT::ntt(NTT::a, NTT::g); NTT::ntt(NTT::b, NTT::g);
    For(i, 0, lim - 1) NTT::a[i] = 1ll * NTT::a[i] * NTT::b[i] % mod;
    NTT::ntt(NTT::a, NTT::ig);
    c.resize(up + 1);
    ICOPY(c, NTT::a);
}
void add(vector<int> &a, vector<int> &b, vector<int> &c) {
    vector<int> res{ (int)max(a.size(), b.size()) };
    For(i, 0, a.size() - 1) res[i] = (res[i] + a[i]) % mod;
    For(i, 0, b.size() - 1) res[i] = (res[i] + b[i]) % mod;
    c = res;
}

struct Mat {
    vector<int> a[3][3];
} uni = { {{{1}, {0}, {0}}, {{0}, {1}, {0}}, {{0}, {0}, {1}}} };
Mat operator * (cst Mat &x, cst Mat &y) {
    Mat res = {};
    For(i, 0, 2) For(j, 0, 2) For(p, 0, 2) {
        vector<int> tmp; mul(x.a[i][j], y.a[j][p], tmp);
        add(res.a[i][p], tmp, res.a[i][p]);
    }
    return res;
}

Mat sol(int l, int r) {
    if(l > r) return uni;
    LL vmd = sum[l] + sum[r] >> 1, md = lower_bound(sum + l, sum + r + 1, vmd) - sum - l;
    Mat tl = sol(l, md - 1), tr = sol(md + 1, r);
    return tl * Mat{ {{H[stk[md]], {0}, {0, ok[stk[md]]}}, {{ok[stk[md]]}, {1}, {0}}, {{0}, {0}, {1}}} } *tr;
}

void dfs2(Tree &T, int u, int pre, int ftp) {
    stk[++tp] = u; dfn[u] = tp;
    sum[tp] = sum[tp - 1] + lsz[u];
    if(Hs[u]) dfs2(T, Hs[u], u, ftp);
    else {
        For(i, dfn[ftp], tp) {
            vector<int> vec;
            for(auto v : T.ch[stk[i]]) if(v != Hs[stk[i]]) {
                dfs2(T, v, stk[i], v);
                vec.pb(v);
            }
            sol(stk[i], vec);
        }
        auto mat = sol(dfn[ftp], tp);
        For(i, 0, 2) add(F[ftp], mat.a[0][i], F[ftp]), add(G[ftp], mat.a[1][i], G[ftp]);
    }
}

vector<int> poi[maxn + 5]; int vir_to[maxn + 5];
int main() {
    freopen("in.txt", "r", stdin);
    read(n); read(k);
    For(i, 1, n) read(c[i]);
    For(i, 1, n) tr[0].get_new(i);
    For(i, 2, n) {
        int u, v; read(u); read(v);
        tr[0].ch[u].pb(v); tr[0].ch[v].pb(u);
    }
    dfs(tr[0], 1, 0);
    ST::init();
    vector<int> vec;
    For(i, 1, n) vec.pb(i);
    sort(vec.begin(), vec.end(), [](cst int &x, cst int &y) {return dfn[x] < dfn[y];});
    for(auto v : vec) poi[c[v]].pb(v);
    int res = 0;
    For(_c, 1, n) {
        vector<int> st;
        st.pb(1); ok[vir_to[1] = tr[_c].get_new(1)] = c[1] == _c;
        for(auto v : poi[_c]) {
            if(v == 1) continue;
            int lc = lca(v, st.back());
            while(st.size() >= 2 && dep[lc] < dep[st[st.size() - 2]]) {
                int uu = vir_to[st[st.size() - 2]], vv = vir_to[st.back()];
                tr[_c].ch[uu].pb(vv);
                st.pop_back();
            }

            if(dep[lc] < dep[st.back()]) {
                int uu = vir_to[lc], vv = vir_to[st.back()];
                tr[_c].ch[uu].pb(vv);
                st.pop_back();
            }
            if(lc != st.back()) {
                ok[vir_to[lc] = tr[_c].get_new(lc)] = 0;
                st.pb(lc);
            }
            ok[vir_to[v] = tr[_c].get_new(v)] = 1;
            st.pb(v);
        }
        while(st.size() >= 2) {
            int uu = vir_to[st[st.size() - 2]], vv = vir_to[st.back()];
            tr[_c].ch[uu].pb(vv); tr[_c].ch[vv].pb(uu);
            st.pop_back();
        }

        dfs1(tr[_c], 1, 0);
        tp = 0; dfs2(tr[_c], 1, 0, 1);
        For(i, 0, min(k, (int)F[1].size() - 1)) res = (res + F[1][i]) % mod;
        For(i, 0, min(k - 1, (int)G[1].size() - 1)) res = (res + G[1][i]) % mod;
    }
    printf("%d\n", res);
    return 0;
}
