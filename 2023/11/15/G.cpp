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

int T, n, k, a[maxn + 5];

int gcd(int x, int y){return y ? gcd(y, x % y) : x;}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int bas = 1000;
pair<LL, LL> sol(int x){
    LL f[2] = {0, 0}, g[2] = {0, -1};
    For(i, 1, n){
        LL ff[2] = {0, 0}, gg[2] = {-1, -1};
        For(o1, 0, 1) if(g[o1] != -1){
            For(o2, 0, 1){
                LL tem = f[o1] + (i == 1 ? 0 : gcd(o1 ? 0 : a[i - 1], o2 ? 0 : a[i]) == 1) * bas + o2 * x;
                if(gg[o2] == -1 || ff[o2] > tem){
                    ff[o2] = tem;
                    gg[o2] = g[o1] + o2;
                }
            }
        }
        For(o, 0, 1){
            f[o] = ff[o];
            g[o] = gg[o];
        }
    }
    if(g[0] == -1) return {f[1], g[1]};
    if(g[1] == -1) return {f[0], g[0]};
    int o = f[1] < f[0];
    return {f[o], g[o]};
}

int main(){
	freopen("in.txt", "r", stdin);
    read(T);
    while(T--){
        read(n); read(k);
        For(i, 1, n) read(a[i]);
        int l = -inf, r = inf;
        while(l < r){
            int mid = l + r >> 1;
            if(sol(mid).sec <= k) r = mid;
            else l = mid + 1;
        }
        pair<LL, LL> pa = sol(l);
        // cout << pa.sec << endl;
        if(pa.sec == k) printf("%d\n", (pa.fir - l * pa.sec) / bas);
        else{
            pair<int, int> pa1 = sol(l - 1);
            int x1 = pa1.sec, y1 = (pa1.fir - l * pa1.sec) / bas, x2 = pa.sec, y2 = (pa.fir - l * pa.sec) / bas;
            cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
            printf("%d\n", y1 + 1ll * (y2 - y1) * (k - x1) / (x2 - x1));
        }
    }
    return 0;
}
