#include<bits/stdc++.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
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
using namespace std;

LL n, k;
vector<LL> vec;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int tot = 100000;
void dfs(LL x, LL ki){
    if(!tot) return;
    if(x == 1 || !ki){
        printf("%lld ", x);
        tot--;
        return;
    }
    for(auto i : vec){
        if(i > x) break;
        if(x % i) continue;
        dfs(i, ki - 1);
        if(!tot) return;
    }
}

int main(){
	// freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    read(n); read(k);
    For(i, 1, n){
        if(1ll * i * i > n) break;
        if(n % i) continue;
        vec.pb(i);
        if(1ll * i * i != n) vec.pb(n / i);
    }
    sort(vec.begin(), vec.end());
    dfs(n, k);
    return 0;
}
