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
#define maxn 2000000
using namespace std;

int n, w, to[maxn + 5], rk[maxn + 5];
LL as[maxn + 5], lpr[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	// freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    read(n); read(w);
    For(i, 1, n) to[i] = 1;
    For(i, 1, maxn) rk[i] = 1;
    For(o, 1, w){
        int k; read(k);
        For(i, 1, k){
            int c; read(c);
            lpr[to[c]] += 1ll * o * rk[to[c]];
            as[c] += lpr[to[c]];
            rk[to[c]]++;
            lpr[to[c]] -= 1ll * o * rk[to[c]];
            to[c]++;
            as[c] -= lpr[to[c]] + 1ll * o * rk[to[c]];
        }
    }
    For(i, 1, maxn) lpr[i] += 1ll * (w + 1) * rk[i];
    For(i, 1, n) printf("%.6Lf\n", (LD)(as[i] + lpr[to[i]] - 1) / w);
	return 0;
}
