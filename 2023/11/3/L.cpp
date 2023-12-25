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

int n, m, k;
struct Data{
    int i, j, op, a, b, d, v;
} dat[105];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

LL mx = 0, a[15];
void dfs(int now){
    if(now > n){
        LL res = 0;
        For(i, 1, m){
            if(dat[i].op == 0){
                if(dat[i].a * a[dat[i].i] + dat[i].b * a[dat[i].j] <= dat[i].d) res += dat[i].v;
            }
            else if(dat[i].a * a[dat[i].i] + dat[i].b * a[dat[i].j] >= dat[i].d) res += dat[i].v;
        }
        mx = max(mx, res);
        return;
    }
    For(o, 0, k) a[now] = o, dfs(now + 1);
}

int main(){
	//freopen("in", "r", stdin);
    read(n); read(m); read(k);
    For(i, 1, m) read(dat[i].i), read(dat[i].j), read(dat[i].op), read(dat[i].a), read(dat[i].b), read(dat[i].d), read(dat[i].v);
    dfs(1);
    printf("%lld\n", mx);
    return 0;
}
