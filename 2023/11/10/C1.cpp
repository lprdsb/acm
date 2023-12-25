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

int n, m, T;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

vector<int*> vec;

int f[55][2][2];
int dfs(int pos, int o1, int o2){
    if(!pos) return 1;
    if(f[pos][o1][o2] != -1) return f[pos][o1][o2];
    int res = dfs(pos - 1, o1 && (!((n >> (pos - 1)) & 1)), o2 && (!((m >> (pos - 1)) & 1)));
    if(!o2 || ((m >> (pos - 1)) & 1)) res = (res + 1ll * dfs(pos - 1, o1 && (!((n >> (pos - 1)) & 1)), o2 && ((m >> (pos - 1)) & 1)) % mod) % mod;
    if(!o1 || ((n >> (pos - 1)) & 1)) res = (res + 1ll * dfs(pos - 1, o1 && ((n >> (pos - 1)) & 1), o2 && (!((m >> (pos - 1)) & 1))) % mod) % mod;
    // cout << res << endl;
    vec.pb(&f[pos][o1][o2]);
    return f[pos][o1][o2] = res;
}

int main(){
	// freopen("in.txt", "r", stdin);
    // cout << ((3 >> 33) & 1) << endl;
    memset(f, -1, sizeof f);
    read(T);
    while(T--){
        read(n); read(m);
        // cout << ((m >> 33) & 1) << endl;
        // cout << dfs(1, 1, 0) << endl;
        int fl1 = 1, fl2 = 1, res = 0;
        Rof(o, 30, 0){
            if(!fl2 || ((m >> o) & 1)) res = (res + 1ll * (o + 1) * dfs(o, fl1 && (!((n >> o) & 1)), fl2 && ((m >> o) & 1)) % mod) % mod;
            if(!fl1 || ((n >> o) & 1)) res = (res + 1ll * (o + 1) * dfs(o, fl1 && ((n >> o) & 1), fl2 && (!((m >> o) & 1))) % mod) % mod;
            // cout << o << " " << res << endl;
            fl1 &= !((n >> o) & 1);
            fl2 &= !((m >> o) & 1);
        }
        printf("%d\n", res);
        for(auto i : vec) *i = -1;
        vec.resize(0);
    }
}
