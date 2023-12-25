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

int n, m, a[maxn + 5], f[905][maxn + 5], b[maxn + 5];
char s[maxn + 5];
vector<pair<int, int> > ch[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

void chkmn(int &x, int y){
    if(y < x) x = y;
}

int q[2 * maxn + 5], l, r;
int main(){
	// freopen("in.txt", "r", stdin);
    memset(f, inf, sizeof f);
    scanf("%s", s + 1); n = strlen(s + 1);
    read(m);
    For(i, 1, n) a[i] = s[i] - 'a';
    For(i, 1, n - 1) b[i] = 26 * a[i] + a[i + 1] + 1;
    For(i, 1, n - 1){
        if(i > 1) ch[i].pb({i - 1, 1});
        if(i < n - 1) ch[i].pb({i + 1, 1});
        ch[i].pb({n + b[i], 0});
        ch[n + b[i]].pb({i, 1}); 
    }
    int bas = 26 * 25 + 26;
    For(o, 1, bas){
        l = r = maxn;
        f[o][n + o] = 0;
        q[l] = n + o;
        while(l <= r){
            int u = q[l++];
            for(auto [v, w] : ch[u]){
                if(f[o][v] > f[o][u] + w){
                    f[o][v] = f[o][u] + w;
                    if(w) q[++r] = v;
                    else q[--l] = v;
                }
            }
        }
    }
    while(m--){
        int s, t, res; read(s); read(t); res = abs(t - s);
        For(i, 1, bas) res = min(1ll * res, 1ll * f[i][s] + f[i][t] - 1);
        printf("%d\n", res);
    }
    return 0;
}
