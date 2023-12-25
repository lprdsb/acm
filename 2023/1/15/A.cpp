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

int mod, n, a[maxn + 5], vis[maxn + 5];
map<int, int> ma;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int fp(int x, int y){
    int asi = 1;
    while(y){
        if(y & 1) asi = 1ll * asi * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return asi;
}

int main(){
	//freopen("in", "r", stdin);
    read(mod); read(n);
    if(mod == n){
        puts("0 1");
        return 0;
    }
    For(i, 1, n) read(a[i]), ma[a[i]] = i;
    if(n == 1){
        printf("%d 0\n", a[1]);
        return 0;
    }
    int d;
    if(2 * n < mod){
        int tem = (1ll * a[2] - a[1] + mod) % mod, cnt = 0;
        For(i, 1, n) if(ma[(1ll * a[i] + tem) % mod]) cnt++;
        d = 1ll * tem * fp(n - cnt, mod - 2) % mod;
    }
    else if(n + 1 == mod){
        For(i, 0, mod - 1) if(!ma[i]){
            printf("%d 1\n", (i + 1) % mod);
            return 0;
        }
    }
    else{
        int cnt = 0, tem;
        For(i, 0, mod - 1) if(!ma[i]){
            For(j, i + 1, mod - 1) if(!ma[j]){
                tem = j - i;
                break;
            }
            break;
        }
        For(i, 0, mod - 1) if(!ma[i] && !ma[(i + tem) % mod]) cnt++;
        d = 1ll * tem * fp(mod - n - cnt, mod - 2) % mod;
        //if(a[1] == 79) cout << d << endl;
    }
    For(i, 1, n) vis[ma[(1ll * a[i] + d) % mod]] = 1;
    int as = -1;
    For(i, 1, n) if(!vis[i]){
        if(as != -1){
            puts("-1");
            return 0;
        }
        as = a[i];
    }
    printf("%d %d\n", as, d);
    return 0;
}
