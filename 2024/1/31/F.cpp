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

#define maxn 200000
int n, k;
vector<int> ch[maxn + 5];

int mx[maxn + 5], son[maxn + 5], dep[maxn + 5];
void dfs(int u) {
    for(auto v : ch[u]) {
        dep[v] = dep[u] + 1;
        dfs(v);
        if(son[u] == 0 || mx[v] > mx[son[u]]) son[u] = v;
    }
    mx[u] = mx[son[u]] + 1;
}

vector<int> vec;
void dfs1(int u, int len) {
    if(!ch[u].size()) vec.pb(2 * len - dep[u]);
    for(auto v : ch[u]) {
        if(v == son[u]) dfs1(v, len + 1);
        else dfs1(v, 1);
    }
}


int main() {
    //freopen("in", "r", stdin);
    read(n); read(k);
    For(i, 2, n) {
        int p; read(p);
        ch[p].pb(i);
    }
    dfs(1);
    dfs1(1, 0);
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    int res = 2 * (n - 1); k++;
    for(auto i : vec) {
        if(i <= 0) break;
        res -= i;
        k--;
        if(!k) break;
    }
    printf("%d\n", res);
    return 0;
}
