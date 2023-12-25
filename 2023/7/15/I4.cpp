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
#define mod 998244353
using namespace std;

int t, inv[50];
LL n, N;
map<LL, int> f;

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

int tot = 0;
int dfs(LL x){
    // cout << (int)(x % mod) << endl;
    if(x > N) return 0;
    if(f.count(x)) return 0;
    tot++;
    int num[10], cnt = 0;
    For(i, 0, 9) num[i] = 0;
    LL tem = x;
    while(tem){
        num[tem % 10]++;
        dfs(x * (tem % 10 + 1));
        tem /= 10;
    }
    // For(i, 1, 9) if(num[i]) ;
    f[x] = 1;
    return 0;
}

unordered_map<LL, int> mma;

int main(){
	freopen("in.txt", "r", stdin);
    For(i, 1, 30) inv[i] = fp(i, mod - 2);
    read(t);
    while(t--){
        // if(t == 1) cout << f.size() << endl;
        read(n); read(N);
        // printf("%d\n", dfs(n));
        cout << t << endl;
        dfs(n);
        // cout << "asd" << endl;
        // For(i, 1, 200){
        //     // cout << "asd" << endl;
        //     // // cout << tot << endl;
        //     for(auto i : f) For(j, 1, 10) mma[i.fir] = 1;
        //     mma.clear();
        // }
        // cout << "1111" << endl;
        f.clear();
    }
    return 0;
}
