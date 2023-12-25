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
#define mod 1000000007
using namespace std;

int T;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int sol(LL n){
    int res = 0;
    For(o, 2, 60){
        LL l = 1ll << o, r = min(n, (1ll << (o + 1)) - 1);
        if(l > r) break;
        LL tem = o;
        int cnt = 1;
        while(tem <= r){
            if((__int128_t)tem * o > 1000000000000000000){
                res = (res + 1ll  * cnt * max(0ll, r - max(l, tem) + 1)) % mod;
                break;
            }
            else res = (res + 1ll * max(0ll, min(r, tem * o - 1) - max(l, tem) + 1) % mod * cnt) % mod;
            // if(res >= mod) res -= mod;
            tem *= o;
            cnt++;
        }
    }
    return res;
}


LL l, r;

int main(){
	// freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    read(T);
    while(T--){
        read(l); read(r);
        // l = 999999999999999719; r = 999999999999999773;
        printf("%lld\n", (1ll * sol(r) - sol(l - 1) + mod) % mod);
    }
    return 0;
}
