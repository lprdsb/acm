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
#define maxn 500
using namespace std;

int n, sum = 0;
LL f[2][5000005], as = Inf;
struct Node{
    int t, a;
    DD val;
} a[maxn + 5];
bool operator < (Node &x, Node &y){
    return x.val < y.val; 
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	//freopen("in", "r", stdin);
    memset(f, inf, sizeof f);
    read(n);
    For(i, 1, n) read(a[i].t);
    For(i, 1, n) read(a[i].a), a[i].val = (DD)a[i].t / a[i].a;
    sort(a + 1, a + n + 1);
    int o = 0;
    f[o][0] = 0;
    For(i, 1, n){
        o ^= 1;
        For(j, 0, sum + a[i].t){
            f[o][j] = Inf;
            if(f[o ^ 1][j] != -1)
                f[o][j] = f[o ^ 1][j] + 1ll * (sum - j) * a[i].a;
            if(j >= a[i].t)
                f[o][j] = min(f[o][j], f[o ^ 1][j - a[i].t] + 1ll * (j - a[i].t) * a[i].a);
            if(i == n) as = min(as, f[o][j]);
        }
        sum += a[i].t;
    }
    printf("%lld\n", as);
    return 0;
}
