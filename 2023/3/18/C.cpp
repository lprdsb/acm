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
#define maxn 200000
using namespace std;

int t, n, m, fa[maxn + 5];
LL as = 0;
pair<int, int> a[maxn + 5];
vector<int> vec[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}

int vis[maxn + 5];
int main(){
	// freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        as = 0;
        read(n); read(m);
        For(i, 1, n) read(a[i].fir), a[i].sec = i, vec[i].clear(), fa[i] = i, vis[i] = 0;
        sort(a + 1, a + n + 1);
        // if(!t){
        //     For(i, 1, n) cout << fa[i] << " "; cout << endl;
        // }
        For(i, 1, m){
            int u, v; read(u); read(v);
            vec[u].pb(v); vec[v].pb(u);
        }
        Rof(i, n, 1){
            vis[a[i].sec] = 1;
            for(auto v : vec[a[i].sec]) if(vis[v]){
                int vv = find(v);
                if(vv != a[i].sec) as -= a[i].fir;
                fa[vv] = a[i].sec;
            }
            as += a[i].fir;
        }
        printf("%lld\n", as);
    }
    return 0;
}
