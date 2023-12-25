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
#define maxn 300000
using namespace std;

LL n, m, x, a[maxn + 5], fa[maxn + 5];
struct Edge{int u, v;} e[maxn + 5];
vector<int> vec[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int as[maxn + 5], st[maxn + 5], top = 0;

int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(m); read(x);
    For(i, 1, n) read(a[i]), fa[i] = i;
    For(i, 1, m){
        int u, v; read(u); read(v);
        e[i] = {u, v};
        vec[u].pb(i);
        vec[v].pb(i);
    }
    priority_queue<pair<LL, int> > q;
    For(i, 1, n) q.push(mp(a[i], i));
    while(q.size()){
        int u = q.top().sec; q.pop();
        if(u != fa[u]) continue;
        top = 0;
        Rof(i, vec[u].size() - 1, 0){
            int tem = vec[u][i], uu = e[tem].u, vv = e[tem].v;
            vec[u].pop_back();
            if(find(uu) != u) swap(uu, vv);
            vv = find(vv);
            if(vv == u) continue;
            as[++as[0]] = tem;
            if(vec[u].size() < vec[vv].size()) swap(vec[u], vec[vv]);
            if(a[u] + a[vv] < x){
                puts("No");
                return 0;
            }
            a[u] = a[u] + a[vv] - x;
            for(auto j : vec[vv]) vec[u].pb(j);
            fa[vv] = u;
            q.push(mp(a[u], u));
            break;
        }
    }
    if(as[0] == n - 1){
        puts("Yes");
        For(i, 1, n - 1) printf("%d\n", as[i]);
    }
    return 0;
}
