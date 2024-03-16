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

#define maxn 200000
int n, k, a[maxn + 5], as[maxn + 5];
struct Opt {
    int l, r, id;
} opt[maxn + 5];


#define mod 998244353
void add(int &x, int y) {
    x += y;
    if(x >= mod) x -= mod;
}
int f[maxn + 5][105], g[105];
void sol(vector<Opt> &vec, int l, int r) {
    if(!vec.size()) return;
    if(l == r) {
        for(auto i : vec) as[i.id]++;
        if(!a[l]) for(auto i : vec) as[i.id]++;
        return;
    }
    int md = l + r >> 1;
    For(i, 0, k - 1) g[i] = 0; g[0] = 1;
    Rof(i, md, l) {
        For(j, 0, k - 1) f[i][j] = 0;
        For(j, 0, k - 1) {
            add(f[i][j], g[j]);
            int to = j + a[i];
            if(to >= k) to -= k;
            add(f[i][to], g[j]);
        }
        For(j, 0, k - 1) g[j] = f[i][j];
    }


    For(i, 0, k - 1) g[i] = 0; g[0] = 1;
    For(i, md + 1, r) {
        For(j, 0, k - 1) f[i][j] = 0;
        For(j, 0, k - 1) {
            add(f[i][j], g[j]);
            int to = j + a[i];
            if(to >= k) to -= k;
            add(f[i][to], g[j]);
        }
        For(j, 0, k - 1) g[j] = f[i][j];
    }
    vector<Opt> vl, vr;
    for(auto i : vec) {
        if(i.r <= md) vl.pb(i);
        else if(i.l > md) vr.pb(i);
        else For(j, 0, k - 1) add(as[i.id], 1ll * f[i.l][j] * f[i.r][(k - j) % k] % mod);
    }
    sol(vl, l, md); sol(vr, md + 1, r);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(k);
    For(i, 1, n) read(a[i]);
    vector<Opt> vec;
    int q; read(q);
    For(i, 1, q) {
        int l, r; read(l); read(r);
        vec.pb({ l, r, i });
    }
    sol(vec, 1, n);
    For(i, 1, q) printf("%d ", as[i]);
}
