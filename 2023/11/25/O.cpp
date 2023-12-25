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


cst int P = 998244353;

int fp(int x, int y){
	int ansi = 1;
	while(y){
		if(y % 2) ansi = 1ll * ansi * x % P;
		x = 1ll * x * x % P;
		y /= 2;
	}
	return ansi;
}

int len = 0, lim = 1, inv_lim;
namespace NTT{
    int g = 3;
    vector<int> rev;
    vector<int> gpw{0, 1};
    void dft(int *f){
        // cout << "asd1" << endl;
        if(rev.size() != lim){
            // cout << "asd" << endl;
            rev.resize(lim);
            int k = __builtin_ctz(lim) - 1;
            For(i, 0, lim - 1) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << k);
        }
        // int tot = 0;
        For(i, 0, lim - 1) if(rev[i] < i) swap(f[rev[i]], f[i]);
        if(gpw.size() < lim){
            int k = __builtin_ctz(gpw.size());
            gpw.resize(lim);
            while((1 << k) < lim){
                int w = fp(g, (P - 1) >> (k + 1));
                For(i, 1 << (k - 1), (1 << k) - 1){
                    // tot++;
                    gpw[i << 1] = gpw[i];
                    gpw[(i << 1) | 1] = 1ll * gpw[i] * w % P;
                }
                k++;
            }
        }
        for(int i = 2; i <= lim; i <<= 1){
            int ii = i >> 1;
            for(int j = 0; j < lim; j += i){
                For(p, 0, ii - 1){
                    // tot++;
                    int tem1 = f[j + p], tem2 = 1ll * gpw[ii + p] * f[j + ii + p] % P;
                    f[j + p] = tem1 + tem2;
                    if(f[j + p] >= P) f[j + p] -= P;
                    f[j + ii + p] = tem1 - tem2;
                    if(f[j + ii + p] < 0) f[j + ii + p] += P;
                }
            }
        }
        // For(i, 0, lim - 1) cout << f[i] << " "; cout << endl;
        // cout << "asd" << endl;
        // cout << tot << endl;
    }
    void idft(int *f){
        reverse(f + 1, f + lim);
        dft(f);
        For(i, 0, lim - 1) f[i] = 1ll * f[i] * inv_lim % P;
    }
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

#define maxn 100000

int n, m, a[maxn + 5], b[maxn + 5], as[4 * maxn + 5], B = 2700;
map<int, int> ma;
int tot = 0;
vector<int> pos[2][2 * maxn + 5];

int F[4 * maxn + 5], G[4 * maxn + 5], H[4 * maxn + 5];

int main(){
	// freopen("in.txt", "r", stdin);
    read(n);
    For(i, 0, n - 1){
        read(a[i]);
        // a[i] = i / 2000;
        if(!ma[a[i]]) ma[a[i]] = ++tot;
        int o = ma[a[i]];
        pos[0][o].pb(i);
    }
    read(m);
    Rof(i, m - 1, 0){
        read(b[i]);
        // b[i] = i / 2000;
        if(!ma[b[i]]) ma[b[i]] = ++tot;
        int o = ma[b[i]];
        pos[1][o].pb(i);
    }
    len = n + m - 1, lim = 1;
    while(lim < len) lim <<= 1;
    inv_lim = fp(lim, P - 2);
    // cout << lim << endl;
    // cout << "asd" << endl;
    for(auto [k, v] : ma) if(pos[0][v].size() && pos[1][v].size()){
        if(pos[0][v].size() + pos[1][v].size() <= B){
            for(auto x1 : pos[0][v]) for(auto x2 : pos[1][v]) as[x1 + x2]++;
        }
        else{
            for(auto x1 : pos[0][v]) F[x1] = 1;
            for(auto x2 : pos[1][v]) G[x2] = 1;
            NTT::dft(F); NTT::dft(G);
            // cout << k << endl;
            For(i, 0, lim - 1){
                H[i] = (H[i] + 1ll * F[i] * G[i]) % P;
                F[i] = G[i] = 0;
            }
        }
    }
    NTT::idft(H);
    // Rof(i, n + n - 2, 0) cout << H[i] << " "; cout << endl;
    Rof(i, n + m - 2, 0){
        int l = max(0, i - m + 1), r = min(n - 1, m - 1 - (-i + m - 1));
        // cout << l << " " << r << endl;
        printf("%d ", r - l + 1 - as[i] - H[i]);
    }
    return 0;
}



