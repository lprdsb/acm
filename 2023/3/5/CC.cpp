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
#define maxn 1000001
#define mod 998244353
using namespace std;

int n, a[2 * maxn + 5], pri[2 * maxn + 5], vis[2 * maxn + 5], cnt = 0, pri_to[2 * maxn + 5];
int M_p[2 * maxn + 5], m_p[2 * maxn + 5], b[4 * maxn + 5], c[4 * maxn + 5], inv2, as = 1;
vector<pair<int, int> > factor[2 * maxn + 5];


template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int fp(int x, int y){
    int asi = 1;
    while(y){
        if(y & 1) asi = 1ll * asi * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return asi;
}

int lim, lim_inv, pol_len, pol_to[4 * maxn + 5], g = 3, ig;
void ntt_pre(int x){
    lim = 1; pol_len = 0;
    while(lim < x) lim <<= 1, pol_len++;
    For(i, 0, lim - 1) pol_to[i] = (pol_to[i >> 1] >> 1) | ((i & 1) << (pol_len - 1));
    lim_inv = fp(lim, mod - 2);
}
void ntt(int *x, int gi){
    For(i, 0, lim - 1) if(i < pol_to[i]) swap(x[i], x[pol_to[i]]);
    for(int i = 2; i <= lim; i <<= 1){
        int ii = i >> 1, w = fp(gi, (mod - 1) / i);
        for(int j = 0; j < lim; j += i){
            int wn = 1;
            For(p, j, j + ii - 1){
                int tem1 = x[p], tem2 = 1ll * wn * x[p + ii] % mod;
                x[p] = (tem1 + tem2) % mod;
                x[p + ii] = (tem1 - tem2 + mod) % mod;
                wn = 1ll * wn * w % mod;
            }
        }
    }
    if(gi == ig)
        For(i, 0, lim - 1) x[i] = 1ll * x[i] * lim_inv % mod;
}

int main(){
	// freopen("in.txt", "r", stdin);
    inv2 = fp(2, mod - 2);
    ig = fp(3, mod - 2);
    For(i, 2, 2 * maxn){
        if(!vis[i]) pri[++cnt] = i, pri_to[i] = i;
        For(j, 1, cnt){
            if(i * pri[j] > 2 * maxn) break;
            vis[i * pri[j]] = 1;
            pri_to[i * pri[j]] = pri[j];
            if(i % pri[j] == 0) break;
        }
    }
    For(i, 2, 2 * maxn){
        int tem = i;
        while(tem != 1){
            int pri_mn = pri_to[tem], cnt_pri = 0;
            while(tem % pri_mn == 0) tem /= pri_mn, cnt_pri++;
            factor[i].pb(mp(pri_mn, cnt_pri));
        }
    }
    read(n);
    For(i, 1, n){
        read(a[i]);
        for(auto j : factor[a[i]]){
            int tem = j.sec;
            if(tem > M_p[j.fir]) swap(M_p[j.fir], tem);
            if(tem > m_p[j.fir]) swap(m_p[j.fir], tem);
        }
    }
    For(i, 1, n){
        int tem = 1;
        for(auto j : factor[a[i]])
            if(j.sec == M_p[j.fir]) tem = 1ll * tem * fp(j.fir, mod - 1 + (m_p[j.fir] - M_p[j.fir])) % mod;
        b[a[i]] = (b[a[i]] + tem) % mod;
        c[2 * a[i]] = (c[2 * a[i]] - 1ll * tem * tem % mod + mod) % mod;
    }
    ntt_pre(2 * maxn - 1);
    ntt(b, g);
    For(i, 0, lim - 1) b[i] = 1ll * b[i] * b[i] % mod;
    ntt(b, ig);
    For(i, 0, lim - 1) c[i] = 1ll * (c[i] + b[i]) % mod * inv2 % mod;
    For(i, 2, maxn) if(M_p[i]) as = 1ll * as * fp(i, M_p[i]) % mod;
    int tem = 0;
    For(i, 0, 2 * maxn){
        int tem1 = 1;
        for(auto j : factor[i]) if(j.sec > M_p[j.fir])
            tem1 = 1ll * tem1 * fp(j.fir, j.sec - M_p[j.fir]);
        tem = (tem + 1ll * tem1 * c[i] % mod) % mod;
        // if(i <= 10) cout << tem1 << " " << c[i] << endl;
    }
    printf("%d\n", 1ll * as * tem % mod);
    return 0;
}
