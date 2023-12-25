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
#define maxn 200000
using namespace std;

int n, a[2][maxn + 5];
LL as = 0;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

LL sol(int x){
    return 1ll * x * (x - 1) / 2 + x;
}

int main(){
	//freopen("in", "r", stdin);
    read(n);
    For(o, 0, 1){
        For(i, 1, n){
            int x; read(x);
            a[o][x] = i;
        }
    }
    as = sol(min(a[0][1] - 1, a[1][1] - 1)) + sol(n - (max(a[0][1], a[1][1]))) + sol(abs(a[0][1] - a[1][1]) - 1);
    int l = inf, r = 0;
    For(i, 1, n){
        int ll = 0, rr = n + 1;
        For(o, 0, 1){
            if(a[o][i] <= r) ll = max(ll, a[o][i]);
            if(a[o][i] >= l) rr = min(rr, a[o][i]);
        }
        // cout << l << " " << r << " " << ll << " " << rr << endl;
        if(i != 1) as += 1ll * max(0, l - ll) * max(0, rr - r);
        For(o, 0, 1){
            l = min(l, a[o][i]);
            r = max(r, a[o][i]);   
        }
    }
    printf("%lld\n", as + 1);
    return 0;
}
