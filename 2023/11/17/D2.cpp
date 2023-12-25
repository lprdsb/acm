#include<bits/stdc++.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(LL i = (a), en = (b); i >= en; --i)
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
#define maxn 10000000
#define mod 998244353
using namespace std;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int sum[maxn + 5];
int get_s(LL n){
    int res = 0;
    For(i, 1, n){
        LL tem = n / i, to = n / tem;
        res = (res + 1ll * tem % mod * (to - i + 1 + mod)) % mod;
        i = to;
    }
    return res;
}

int vis[maxn + 5], pri[maxn + 5], cnt = 0;

LL n;
int main(){
	// freopen("in.txt", "r", stdin);
    sum[1] = 1;
    For(i, 2, maxn){
        if(!vis[i]) pri[++cnt] = i, sum[i] = mod - 1;
        for(int j = 1; j <= cnt && i * pri[j] <= maxn; ++j){
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
            else sum[i * pri[j]] = mod - sum[i];
        }
    }
    For(i, 2, maxn) sum[i] = (sum[i - 1] + sum[i]) % mod;
    // cout << get_s(4) << endl;
    read(n);
    int pre = 0, res = 0;
    For(i, 1, inf){
        LL tem = n / i / i;
        if(!tem) break;
        LL to = sqrt(n / tem), tem1 = sum[to];
        assert(to <= maxn);
        res = (res + 1ll * get_s(tem) * (tem1 - pre + mod)) % mod;
        pre = tem1;
        i = to;
    }
    printf("%lld\n", res);
	return 0;
}