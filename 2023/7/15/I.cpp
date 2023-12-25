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
// unordered_map<LL, int> f;

class Hash{
    public:
        int mod1 = 999997, hd[10000005];
        vector<int> vec;
        struct Edge{
            LL key;
            int val, net;
        };
        vector<Edge> e;
        int find(LL x){
            vec.pb(x % mod1);
            for(int i = hd[x % mod1]; ~i; i = e[i].net)
                if(e[i].key == x) return 1;
            return 0;
        }
        int& operator [] (cst LL x){
            for(int i = hd[x % mod1]; ~i; i = e[i].net)
                if(e[i].key == x) return e[i].val;
            e.pb({x, 0, (int)e.size() - 1});
            hd[x % mod1] = e.size() - 1;
            return e[e.size() - 1].val;
        }
        Hash(){memset(hd, -1, sizeof hd);}
        void clear(){
            for(auto i : vec) hd[i] = -1;
            vec.resize(0);
        }
} f;

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
    tot++;
    // cout << (int)x << endl;
    if(x > N) return 0;
    if(f.find(x)) return f[x];
    int num[10], cnt = 0;
    For(i, 0, 9) num[i] = 0;
    LL tem = x;
    while(tem){
        num[tem % 10]++;
        cnt++;
        tem /= 10;
    }
    LL asi = cnt;
    For(i, 1, 9) if(num[i]) asi = (asi + 1ll * num[i] * dfs(x * (i + 1)));
    return f[x] = 1ll * asi % mod * inv[cnt - num[0]] % mod;
}

int main(){
	freopen("in.txt", "r", stdin);
    For(i, 1, 30) inv[i] = fp(i, mod - 2);
    read(t);
    while(t--){
        // if(t == 1) cout << f.size() << endl;
        read(n); read(N);
        printf("%d\n", dfs(n));
        // dfs(n);
        // cout << tot << endl;
        f.clear();
    }
    return 0;
}
