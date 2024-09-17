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
#define maxn 200000
using namespace std;

#define mod 998244353
int n, q, fac[maxn + 5], ifac[maxn + 5], inv[maxn + 5];

int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return res;
}
struct Node { int ch[2], fa; };
int res = 1;
int fa[maxn + 5], sz[maxn + 5];
class Lct_Tree {
    public:
    int tot = 0;
    Node poi[maxn + 5];
    Lct_Tree() {}
    void init(int _tot) {
        tot = _tot;
    }
    void chk() {
        cout << "asd" << endl;
        For(i, 1, n) cout << i << " " << is_rt(i) << " " << poi[i].fa << endl;
    }
    void rot(int rt) {
        int fa = poi[rt].fa;
        int is_ls = poi[fa].ch[0] == rt;
        if(!is_rt(fa)) poi[poi[fa].fa].ch[poi[poi[fa].fa].ch[1] == fa] = rt;
        poi[rt].fa = poi[fa].fa;
        poi[poi[fa].ch[!is_ls] = poi[rt].ch[is_ls]].fa = fa;
        poi[poi[rt].ch[is_ls] = fa].fa = rt;
    }
    bool is_rt(int rt) {
        if(!rt) return 1;
        return poi[poi[rt].fa].ch[0] != rt && poi[poi[rt].fa].ch[1] != rt;
    }
    void spy(int x) { while(!is_rt(x)) rot(x); }
    int fdmn(int x) {
        while(poi[x].ch[0]) x = poi[x].ch[0];
        return x;
    }
    void acc(int x) {
        int now = x, pre = 0;
        while(now) {
            spy(now);
            int tem = fdmn(poi[now].ch[1]);
            res = 1ll * res * inv[sz[tem]] % mod;
            res = 1ll * res * sz[pre] % mod;
            // cout << now << " " << res << " " << 1ll * sz[pre] * inv[sz[pre]] % mod << endl;
            poi[now].ch[1] = pre;
            // cout << now << " " << res << endl;
            pre = now;
            now = poi[now].fa;
            pre = fdmn(pre); spy(pre);
        }
        spy(x);
    }
} tr;

template <class T>
void read(T &x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}


int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(q);
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[maxn] = fp(fac[maxn], mod - 2);
    Rof(i, maxn - 1, 0) ifac[i] = 1ll * (i + 1) * ifac[i + 1] % mod;
    For(i, 1, maxn) inv[i] = 1ll * ifac[i] * fac[i - 1] % mod;
    // cout << fac[2] << endl;
    tr.init(n);
    For(i, 2, n) read(fa[i]), tr.poi[i].fa = fa[i];
    For(i, 0, n) sz[i] = 1;
    Rof(i, n, 2) sz[fa[i]] += sz[i];
    res = fac[n];
    For(i, 1, n) res = 1ll * res * inv[sz[i]] % mod;
    while(q--) {
        int u; read(u);
        tr.acc(u);
        printf("%d\n", res);
    }
    return 0;
}

