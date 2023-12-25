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

int n, m, k, a[maxn + 5], b[2 * maxn + 5], as = 0;
struct Mat{
    int a[2][2];
};
Mat operator * (Mat &x, Mat &y){
    Mat asi = {};
    asi.a[0][0] = (1ll * x.a[0][0] * y.a[0][0] + 1ll * x.a[0][1] * y.a[1][0]) % mod;
    asi.a[0][1] = (1ll * x.a[0][0] * y.a[0][1] + 1ll * x.a[0][1] * y.a[1][1]) % mod;
    asi.a[1][0] = (1ll * x.a[1][0] * y.a[0][0] + 1ll * x.a[1][1] * y.a[1][0]) % mod;
    asi.a[1][1] = (1ll * x.a[1][0] * y.a[0][1] + 1ll * x.a[1][1] * y.a[1][1]) % mod;
    return asi;
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int to[maxn + 5];

int main(){
	//freopen("in", "r", stdin);
    read(n); read(m); read(k);
    For(i, 1, n){
        read(a[i]);
        a[i] = m - a[i] % m;
    }
    Rof(i, n, 2) a[i] = (1ll * a[i] - a[i - 1] + m) % m;
    For(i, 1, n){
        read(b[i]);
        b[i] %= m;
        b[n + i] = b[i];
    }
    Rof(i, 2 * n, 2) b[i] = (1ll * b[i] - b[i - 1] + m) % m;
    Mat asi = {{{1, 0}, {0, 1}}}, tra = {{{0, n - 1}, {1, n - 2}}};
    while(k){
        if(k & 1) asi = asi * tra;
        tra = tra * tra;
        k >>= 1;
    }

    int now = to[2] = 1;
    For(i, 3, n){
        while(now != 1 && a[now + 1] != a[i]) now = to[now];
        if(a[now + 1] == a[i]) now++;
        to[i] = now;
    }
    now = 1;
    a[n + 1] = 114514;
    For(i, 2, 2 * n - 1){
        while(now != 1 && a[now + 1] != b[i]) now = to[now];
        if(a[now + 1] == b[i]) now++;
        if(now == n){
            if(i == n) as = (1ll * as + asi.a[0][0]) % mod;
            else as = (1ll * as + asi.a[1][0]) % mod;
        }
    }
    printf("%d\n", as);
    return 0;
}
