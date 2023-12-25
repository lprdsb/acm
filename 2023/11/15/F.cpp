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
#define maxn 500000
using namespace std;

int T, q, n = 1;
vector<int> ch[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

struct Opt{
    int op, v, x;
} opt[maxn + 5];

int sz[maxn + 5], id[maxn + 5], tim = 0;
void dfs(int u){
    id[u] = ++tim;
    sz[u] = 1;
    for(auto v : ch[u]){
        dfs(v);
        sz[u] += sz[v];
    }
}

LL tr[maxn + 5];
void ins(int x, LL y){
    while(x <= n) tr[x] += y, x += x & -x;
}
LL que(int x){
    LL res = 0;
    while(x) res += tr[x], x -= x & -x;
    return res;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(T);
    while(T--){
        read(q);
        For(_, 1, q){
            int op, v, x; read(op);
            if(op == 1){
                read(v);
                opt[_] = {op, ++n};
                ch[v].pb(n);
            }
            else{
                read(v); read(x);
                opt[_] = {op, v, x};
            }
        }
        dfs(1);
        For(_, 1, q){
            int op = opt[_].op, v = opt[_].v, x = opt[_].x;
            if(op == 1){
                LL tem = que(id[v]);
                ins(id[v], -tem);
                ins(id[v] + sz[v], tem);
            }
            else{
                ins(id[v], x);
                ins(id[v] + sz[v], -x);
            }
        }
        For(i, 1, n) printf("%lld ", que(id[i])); puts("");
        For(i, 1, n){
            ch[i].resize(0);
            tr[i] = 0;
        }
        tim = 0;
        n = 1;
    }
}
