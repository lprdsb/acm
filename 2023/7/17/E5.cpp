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

int n, a[maxn + 5], hd[maxn + 5], len = 0;
struct Edge{
    int v, net;
} e[2 * maxn + 5];
void add(int u, int v){
    e[len] = {v, hd[u]};
    hd[u] = len++;
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

DD f[maxn + 5];
set<pair<DD, pair<int, int> > > se[maxn + 5];
void dfs(int u, int pre){
    int fl = 0;
    Tra(u, i){
        int v = e[i].v;
        if(v == pre) continue;
        fl = 1;
        dfs(v, u);
        f[u] += f[v];
        if(se[u].size() < se[v].size()) swap(se[u], se[v]);
        for(auto j : se[v]) se[u].insert(j);
    }
    if(fl){
        DD sum = 0, k = 0, x, ppre = 0;
        while(666){
            auto it = ++se[u].begin();
            if(sum + k * (it->fir - ppre) + 2 * (it->fir - a[u]) > -eps){
                x = (2 * a[u] + ppre * k - sum) / (k + 2);
                // printf("%.10lf\n", f[u] + (2 * sum + k * (x - ppre)) * (x - ppre) / 2 + (x - a[u]) * (x - a[u]));
                f[u] = f[u] + (2 * sum + k * (x - ppre)) * (x - ppre) / 2 + (x - a[u]) * (x - a[u]);
                // printf("%.10lf\n", f[u]);
                // cout << pre << endl;
                break;
            }
            DD tem = sum;
            sum += k * (it->fir - ppre);
            f[u] += (tem + sum) * (it->fir - ppre) / 2;
            ppre = it->fir;
            k += it->sec.fir;
            se[u].erase(it);
        }
        se[u].insert({x, {k + 2, u}});
        // if(u == 114){
        //     cout << "asd" << endl;
            // for(auto i : se[u]) cout << i.fir << " " << i.sec.fir << endl;
        // }
    }
    else{
        f[u] = 0;
        se[u].insert({0, {0, u}});
        se[u].insert({(DD)a[u], {2, u}});
        se[u].insert({(DD)Inf, {inf, u}});
    }
}

int main(){
	// freopen("in.txt", "r", stdin);
    memset(hd, -1, sizeof hd);
    read(n);
    For(i, 1, n) read(a[i]);
    For(i, 1, n - 1){
        int u, v; read(u); read(v);
        add(u, v); add(v, u);
    }
    dfs(1, 0);
    printf("%.10lf\n", f[1]);
    return 0;
}
