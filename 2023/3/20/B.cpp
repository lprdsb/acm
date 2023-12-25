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
#define maxn 400000
#define maxm 200000
#define mod 998244353
using namespace std;

int t, n, m, fac[maxn + 5], ifac[maxn + 5], ok[maxn + 5], k, as;
vector<int> to, _tr, _ok;

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

int tr[maxn + 5], lim, len;
void add(int x, int y){while(x < lim) tr[x] += y, x += x & -x;}
int find(int x){
    int sum = 0, now = 0;
    Rof(i, len - 1, 0){
        int tem = now | (1 << i);
        // cout << tr[tem] << endl;
        // if(x == 2) cout << now << " " << sum << " " << tr[tem] << endl;
        if(sum + tr[tem] < x) now = tem, sum += tr[tem];
    }
    return now + 1;
}

int c(int x, int y){
    return 1ll * fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}

int main(){
	// freopen("in.txt", "r", stdin);
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[maxn] = fp(fac[maxn], mod - 2);
    Rof(i, maxn - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
    lim = 1; len = 0;
    while(lim <= maxm) lim <<= 1, len++;
    For(i, 1, lim - 1) tr[i] = i & -i;
    For(i, 1, maxn) ok[i] = 1;
    read(t);
    while(t--){
        k = as = 0;
        read(n); read(m);
        For(i, 1, m){
            int x, y; read(x); read(y);
            to.pb(y);
        } 
        Rof(i, m - 1, 0){
            int tem = find(to[i]);
            // cout << tem << endl;
            if(ok[tem + 1]) k++;
            add(tem, -1);
            _tr.pb(tem);
            ok[tem] = 0;
            _ok.pb(tem);
        }
        for(auto i : _tr) add(i, 1);
        for(auto i : _ok) ok[i] = 1;
        to.clear();
        _tr.clear();
        _ok.clear();
        // cout << k << endl;
        printf("%d\n", c(2 * n - k - 1, n));
    }
    return 0;
}
