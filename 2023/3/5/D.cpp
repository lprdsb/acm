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
#define maxn 100000
using namespace std;

int n, q, vv, cc;
LL f[maxn + 5], mn;
struct Node{int c, v;} a[55];
bool operator < (cst Node &x, cst Node &y){
    return 1ll * x.c * y.v < 1ll * x.v * y.c;
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

void chkmx(LL &x, LL y){if(x < y) x = y;}
int gcd(int x, int y){return y ? gcd(y, x % y) : x;}

int main(){
	// freopen("in.txt", "r", stdin);
    memset(f, -inf, sizeof f); mn = f[0];
    read(n); read(q);
    For(i, 1, n) read(a[i].v), read(a[i].c);
    sort(a + 1, a + n + 1);
    vv = a[n].v;
    cc = a[n].c;
    f[0] = 0;
    For(i, 1, n - 1){
        int gc = gcd(vv, a[i].v);
        For(o, 0, gc - 1){
            For(j, 0, 1){
                int now = o;
                For(p, 1, vv / gc){
                    if(f[now] != mn) chkmx(f[(now + a[i].v) % vv], f[now] + a[i].c - 1ll * (now + a[i].v) / vv * cc);
                    now = (now + a[i].v) % vv;
                }
            }
        }
    }
    while(q--){
        LL tem; read(tem);
        if(f[tem % vv] == mn) puts("-1");
        else printf("%lld\n", tem / vv * cc + f[tem % vv]);
    }
    return 0;
}
