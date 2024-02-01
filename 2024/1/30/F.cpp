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
using namespace std;

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define maxn 300000
int n, m, q, fa[maxn + 5], vis[maxn + 5];
priority_queue<int> Q[maxn + 5];
pair<int, int> opt[maxn + 5], e[maxn + 5];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void merge(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return;
    if(Q[u].size() < Q[v].size()) swap(u, v);
    while(Q[v].size()) Q[u].push(Q[v].top()), Q[v].pop();
    fa[v] = u;
}

vector<int> as;
int main() {
    //freopen("in", "r", stdin);
    read(n); read(m); read(q);
    For(i, 1, n) {
        int x; read(x);
        Q[i].push(x);
    }
    For(i, 1, n) fa[i] = i;
    For(i, 1, m) read(e[i].fir), read(e[i].sec);
    For(i, 1, q) {
        read(opt[i].fir); read(opt[i].sec);
        if(opt[i].fir == 2) vis[opt[i].sec] = 1;
    }
    For(i, 1, m) if(!vis[i]) {
        int u = e[i].fir, v = e[i].sec;
        merge(u, v);
    }
    Rof(i, q, 1) {
        if(opt[i].fir == 1) {
            as.pb(mx[find(opt[i].sec)]);
        }
        else {
            int u = e[opt[i].sec].fir, v = e[opt[i].sec].sec;
            mx[find(v)] = max(mx[find(v)], mx[find(u)]);
            fa[find(u)] = find(v);
        }
    }
    reverse(as.begin(), as.end());
    for(auto i : as) printf("%d\n", i);
}
