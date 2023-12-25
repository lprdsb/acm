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
#define maxn 1000000
#define mod 1000000007
using namespace std;

int n, k, w[15], c[maxn + 5], d[maxn + 5], v[2][11][maxn + 5], as = 1, inv[maxn + 5], ffp[55][55], fac[maxn + 5], ifac[maxn + 5];

int fp(int x, int y){
    int asi = 1;
    while(y){
        if(y & 1) asi = 1ll * asi * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return asi;
}
void add(int &x, int y){
    x += y;
    if(x >= mod) x -= mod;
}
class Poly{
    public:
        vector<int> a;
        int size(){return a.size();}
        int& operator [] (cst int &x){return a[x];}
        Poly(){};
        Poly(int len){a.resize(len);}
        Poly(vector<int> &x){
            a.resize(x.size() + 1);
            a[0] = 1;
            for(auto i : x){
                Rof(j, x.size(), 0){
                    a[j] = 1ll * a[j] * (mod - i) % mod;
                    if(j) add(a[j], a[j - 1]);
                }
            }
        }
        Poly(vector<int> &x, vector<int> &y){
            vector<int> tem(x.size() - 1);
            a.resize(x.size());
            For(i, 0, x.size() - 1){
                int mul = 1ll * y[i] *  ifac[x.size() - 1 - i] % mod * ifac[i] % mod;
                if((x.size() - 1 - i) & 1) mul = mod - mul;
                For(j, 0, x.size() - 1) if(i != j) tem[j - (j > i)] = x[j];
                Poly l(tem);
                For(j, 0, l.size() - 1) add(a[j], 1ll * mul * l[j] % mod);
            }
        }
};

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}


int get_val(vector<int> &px, vector<int> &py, int x){
    int asi = 0;
    For(i, 0, px.size() - 1){
        int mul = 1ll * py[i] *  ifac[px.size() - 1 - i] % mod * ifac[i] % mod;
        // cout << i << " " << mul << endl;
        if((px.size() - 1 - i) & 1) mul = mod - mul;
        For(j, 0, px.size() - 1) if(i != j)
            mul = 1ll * (x - px[j] + mod) % mod * mul % mod;
        add(asi, mul);
    }
    return asi;
}

int main(){
	// freopen("in.txt", "r", stdin);
    For(i, 0, 20){
        ffp[i][0] = 1;
        For(j, 1, 20) ffp[i][j] = 1ll * ffp[i][j - 1] * i % mod;
    }
    inv[1] = fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
    For(i, 2, maxn){
        inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
        fac[i] = 1ll * fac[i - 1] * i % mod;
        ifac[i] = 1ll * ifac[i - 1] * inv[i] % mod;
    }
    read(n); read(k);
    For(i, 1, k) read(w[i]), as = 1ll * as * w[i] % mod;
    For(i, 1, n) read(c[i]), read(d[i]);
    int now[11] = {}, mn[11] = {}, mx[11] = {};
    For(i, 1, n){
        now[c[i]] += d[i];
        if(now[c[i]] < mn[c[i]]) v[0][c[i]][i] = 1, mn[c[i]] = now[c[i]];
        if(now[c[i]] > mx[c[i]]) v[0][c[i]][i] = 1, mx[c[i]] = now[c[i]];
    }
    For(i, 1, n){
        now[c[i]] += d[i];
        if(now[c[i]] < mn[c[i]]) v[1][c[i]][i] = 1, mn[c[i]] = now[c[i]];
        if(now[c[i]] > mx[c[i]]) v[1][c[i]][i] = 1, mx[c[i]] = now[c[i]];
    }
    For(o, 1, k) For(i, 1, n) v[0][o][i] += v[0][o][i - 1], v[1][o][i] += v[1][o][i - 1];
    For(i, 1, n){
        int asi = 1;
        For(o, 1, k){
            if(w[o] - v[0][o][i] >= 1) asi = 1ll * asi * (w[o] - v[0][o][i]) % mod;
            else asi = 0;
        }
        as = (as + asi) % mod;
    }
    For(o, 1, k) w[o] -= v[0][o][n];
    For(i, 1, n){
        int lim = inf, mul = 1;
        vector<int> x, y;
        For(o, 1, k){
            int m = mod - v[1][o][n], im = mod - inv[v[1][o][n]];
            if(v[1][o][n]) mul = 1ll * mul * m % mod;
            if(w[o] - v[1][o][i] >= 0){
                if(v[1][o][n]){
                    lim = min(lim, (w[o] - v[1][o][i]) / v[1][o][n]);
                    x.pb((-1ll * w[o] + v[1][o][i] + mod) % mod * im % mod);
                }
                else mul = 1ll * (w[o] - v[1][o][i] + mod) * mul % mod;
            }
            else{
                lim = -1;
                break;
            }
        }
        if(lim == inf){
            puts("-1");
            return 0;
        }
        Poly poli(x);
        for(auto &j : poli.a) j = 1ll * j * mul % mod;
        x.clear();
        x.resize(poli.size() + 1, 0);
        y.resize(poli.size() + 1, 0);
        For(i, 0, x.size() - 1) x[i] = i;
        For(j, 0, poli.size()){
            if(j) y[j] = y[j - 1];
            For(p, 0, poli.size() - 1) add(y[j], 1ll * poli[p] * ffp[j][p] % mod);
        }
        add(as, get_val(x, y, lim));
    }
    printf("%d\n", as);
    return 0;
}
