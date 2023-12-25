#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define LL __int128_t
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

int t;
LL n, k;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

LL sol(LL p){
    if(p == 1) return inf;
    LL asi = 0, tem = n;
    while(tem) asi += tem % p, tem /= p;
    return asi;
}

LL fp(LL x, int y){
    LL asi = 1;
    while(y){
        if(y & 1) asi *= x;
        x *= x;
        y >>= 1;
    }
    return asi;
}

LL up = 100;

int main(){
	// freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        read(n); read(k);
        if(k >= n) puts("1");
        else{
            LL as = sol(2), lim = 1;
            For(i, 3, min(up, k)) as = min(as, sol(i));
            if(k > up){
                LL pw = up + 1;
                while(pw <= n){
                    For(i, 1, as){
                        if(pw * i > n) break;
                        For(j, 0, as - i){
                            if(pw * i + (pw / (up + 1)) * j > n) break;
                            LL l = up + 1, r = exp(((DD)n / i) * log(1.0 / lim)) + 100;
                            while(l < r){
                                LL mid = l + r >> 1;
                                if(fp(mid, lim) * i + fp(mid, lim - 1) * j > n) r = mid;
                                else l = mid + 1;
                            }
                            if(fp(l, lim) * i + fp(l, lim - 1) * j > n) l--;
                            as = min(as, sol(l));
                        }
                    }
                    lim++;
                    pw *= up + 1;
                }
            }
            printf("%d\n", (int)as);
        }
    }
}
