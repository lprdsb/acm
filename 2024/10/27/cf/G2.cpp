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

#define maxn 300000
#define P 998244353

int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % P;
        x = 1ll * x * x % P;
        y >>= 1;
    }
    return res;
}

int T, n, m, a[maxn + 5], fac[maxn + 5], ifac[maxn + 5], pw[maxn + 5][30];

int pa[maxn + 5][2];
int f[maxn + 5][2], tl[maxn + 5], tr[maxn + 5], pwn[maxn + 5];
int as[2];

void dfs(int l, int r, int vl, int vr) {
    if(l == r) {
        if(r != n) vl--;
        tl[l] = vl;
        tr[l] = vr;
        return;
    }
    int md = l + r >> 1;
    dfs(l, md, vl + 1, vr); dfs(md + 1, r, vl, vr + 1);
}

void sol(vector<int> &v, int l, int r, int val) {
    if(!v.size()) return;
    // cout << l << " " << r << " " << f[6][0] << endl;
    if(l == r) {
        if(l != n) val--;
        if(f[l][0] > as[0]) as[0] = f[l][0], as[1] = 0;
        if(f[l][0] == as[0]) as[1] = (as[1] + 1ll * f[l][1] * pw[n - pa[v[0]][1] + 1][val] % P * pwn[n - l - val]) % P;
        return;
    }
    int md = l + r >> 1;
    vector<int> vl, vr;
    for(auto idx : v) {
        if(pa[idx][0] <= md) {
            vl.pb(idx);
            if(pa[idx][0] != md) tl[pa[idx][0]]--;
        }
        else vr.pb(idx), tr[pa[idx][0]]--;
    }
    sol(vl, l, md, val + 1);
    // cout << l << " " << r << " " << f[6][1] << endl;
    // for(auto v : vr) cout << v << " asd "; cout << endl;
    // if(l == 1 && r == 6) cout << vr.size() << endl;
    int now = 0, mx[3] = { -1, 0 , 0 }, fl = -1;
    for(auto idx : vr) {
        // if(l == 1 && r == 6) cout << (pa[vl[now]][0] != md) << endl;
        while(now < vl.size() && pa[vl[now]][1] <= pa[idx][1]) {
            int pl = vl[now];
            if(pa[pl][0] == md) fl = pl;
            if(f[pa[pl][0]][1] && pa[pl][0] != md) {
                if(f[pa[pl][0]][0] > mx[0]) mx[0] = f[pa[pl][0]][0], mx[1] = mx[2] = 0;
                if(f[pa[pl][0]][0] == mx[0]) {
                    mx[1] = (mx[1] + 1ll * f[pa[pl][0]][1] * pw[n - pa[pl][1] + 1][tl[pa[pl][0]]] % P * pwn[md - pa[pl][0] - tl[pa[pl][0]] - 1] % P) % P;
                    mx[2] = (mx[2] + 1ll * f[pa[pl][0]][1] * pw[n - pa[pl][1] + 1][tl[pa[pl][0]]] % P * pwn[md - pa[pl][0] - tl[pa[pl][0]] - 1] % P * pa[pl][1] % P) % P;
                    // if(l == 1 && r == 6) cout << mx[0] << " " << mx[1] << " " << pa[pl][0] << endl;
                }
            }
            // if(l == 1 && r == 30) cout << pa[pl][0] << " " << mx[0] << " " << f[14][1] << endl;
            now++;
        }
        // if(l == 1 && r == 6) cout << mx[0] << endl;
        f[pa[idx][0]][1] = 1ll * f[pa[idx][0]][1] * pwn[md - l] % P * (pa[idx][1] - 1) % P;
        if(fl != -1 && f[md][0] >= mx[0] && f[md][1]) {
            if(f[md][0] == mx[0]) {
                if(mx[0] + 1 > f[pa[idx][0]][0]) {
                    f[pa[idx][0]][0] = mx[0] + 1;
                    f[pa[idx][0]][1] = 0;
                }
                if(mx[0] + 1 == f[pa[idx][0]][0]) {
                    f[pa[idx][0]][1] = (f[pa[idx][0]][1] + 1ll * mx[1] * pa[idx][1] - mx[2] + P) % P;
                    f[pa[idx][0]][1] = (f[pa[idx][0]][1] + f[md][1]) % P;
                }
            }
            else {
                if(f[md][0] + 1 > f[pa[idx][0]][0]) {
                    f[pa[idx][0]][0] = f[md][0] + 1;
                    f[pa[idx][0]][1] = 0;
                    // cout << l << " " << r << " " << pa[idx][0] << " " << f[5][1] << endl;
                }
                if(f[md][0] + 1 == f[pa[idx][0]][0]) f[pa[idx][0]][1] = (f[pa[idx][0]][1] + f[md][1]) % P;
            }
        }
        else {

            if(mx[0] + 1 > f[pa[idx][0]][0]) {
                f[pa[idx][0]][0] = mx[0] + 1;
                f[pa[idx][0]][1] = 0;
            }
            if(mx[0] + 1 == f[pa[idx][0]][0]) {
                // if(l == 9 && r == 15 && pa[idx][0] == 14) cout << 1ll * mx[1] << endl;
                f[pa[idx][0]][1] = (f[pa[idx][0]][1] + 1ll * mx[1] * pa[idx][1] - mx[2] + P) % P;
            }
        }
        // cout << l << " " << r << " " << idx << endl;
    }
    // cout << l << " " << r << " " << f[6][1] << endl;

    // cout << l << " " << r << endl;
    sol(vr, md + 1, r, val);
    for(auto idx : v) {
        if(pa[idx][0] <= md) {
            vl.pb(idx);
            if(pa[idx][0] != md) tl[pa[idx][0]]++;
        }
        else vr.pb(idx), tr[pa[idx][0]]--;
    }
}

void mian() {
    as[0] = as[1] = 0;
    read(n); read(m);
    pwn[0] = 1;
    For(i, 1, n) pwn[i] = 1ll * pwn[i - 1] * n % P;
    For(i, 1, m) read(pa[i][0]), read(pa[i][1]);
    dfs(1, n, 0, 0);
    For(i, 1, n) f[i][0] = f[i][1] = 1;
    // cout << tl[11] << endl;
    // For(i, 1, n)
    vector<int> v;
    For(i, 1, m) v.pb(i);
    sort(v.begin(), v.end(), [](int x, int y) {return pa[x][1] < pa[y][1];});
    sol(v, 1, n, 0);
    if(as[1]) printf("%d %d\n", m - as[0], as[1]);
    else printf("%d %d\n", m, pwn[n]);
}

int main() {
    // freopen("in.txt", "r", stdin);
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % P;
    ifac[maxn] = fp(fac[maxn], P - 2);
    Rof(i, maxn - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % P;
    For(i, 0, maxn) {
        pw[i][0] = 1;
        For(j, 1, 20) pw[i][j] = 1ll * pw[i][j - 1] * i % P;
    }
    read(T);
    while(T--) {
        mian();
    }
}
