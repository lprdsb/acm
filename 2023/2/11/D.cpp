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
#define mod 998244353
using namespace std;

int n, as = 1, sum[maxn + 5];
LL c, a[maxn + 5], sq3c = 1;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

LL sol(LL x){
    if(!x) return Inf;
    if(c / x / x / x >= 1) return c / x / x;
    return sqrt(c / x);
}

LL sqrt(LL x){
    if(!x) return 0;
    LL l = 1, r = inf;
    while(l < r){
        LL mid = l + r >> 1;
        if(x / mid / mid < 1) r = mid;
        else l = mid + 1;
    }
    return l - 1;
}

int get_f(LL ul, LL ur){
    // cout << ul << " " << ur << endl;
    int asi = 0;
    LL lim = sqrt(c / (ur + 1)), tem = min(ur, lim);
    tem = min(tem, min(ul, sq3c));
    asi = (1ll * ur % mod * (tem + 1) % mod - 1ll * (tem + 1) * tem / 2 % mod + mod) % mod;
    // cout << sum[2] << endl;
    if(lim < sq3c && lim < ul) asi = (1ll * asi + sum[min(ul, sq3c)] - sum[lim] + mod) % mod;
    return asi;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(c);
    while(c / sq3c / sq3c / sq3c >= 1) sq3c++;
    sq3c--;
    For(i, 1, n) read(a[i]);
    For(i, 1, n) if(a[i] > 0 && a[i - 1] > 0 && c / a[i] / a[i - 1] < min(a[i], a[i - 1])){
        puts("0");
        return 0;
    }
    For(i, 1, n) if(a[i - 1] <= 0 && a[i] == -1 && a[i + 1] <= 0){
        puts("-1");
        return 0;
    }
    For(i, 1, maxn){
        if(c / i / i / i < 1) break;
        sum[i] = (sum[i - 1] + c / i / i % mod - i + mod) % mod;
    }
    For(i, 1, n) if(a[i] == -1){
        if(a[i + 1] == -1){
            LL ul = sol(a[i - 1]), ur = sol(a[i + 2]), asi = min(sq3c, min(ul, ur)) + 1;
            asi = (asi + 1ll * get_f(ul, ur) + get_f(ur, ul)) % mod;
            as = 1ll * as * asi % mod;
            i++;
        }
        else as = 1ll * as * (min(sol(a[i - 1]), sol(a[i + 1])) % mod + 1) % mod;
    }
    printf("%d\n", as);
    return 0;
}
