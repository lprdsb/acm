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

#define maxn 2000
int T, n;
vector<int> ch[maxn + 5];

int dep[maxn + 5], fa[maxn + 5];
void dfs(int u, int pre) {
    fa[u] = pre;
    dep[u] = dep[pre] + 1;
    for(auto v : ch[u]) if(v != pre) dfs(v, u);
}

void mian() {
    read(n);
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v);
        ch[v].pb(u);
    }
    dfs(1, 0);
    int mx = 0;
    For(i, 1, n) if(dep[i] > dep[mx]) mx = i;
    dfs(mx, 0);
    vector<int> vec;
    mx = 0;
    For(i, 1, n) if(dep[i] > dep[mx]) mx = i;
    int now = mx;
    while(now) vec.pb(now), now = fa[now];
    if((vec.size() & 1) || vec.size() % 4 == 2) {
        int tem = vec.size() >> 1;
        printf("%d\n", tem + 1);
        For(i, 0, tem) printf("%d %d\n", vec[tem], i);
    }
    else {
        printf("%d\n", vec.size() / 2);
        for(int i = vec.size() / 2 - 1; i >= 1; i -= 2) printf("%d %d\n%d %d\n", vec[vec.size() / 2 - 1], i, vec[vec.size() / 2], i);
    }
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) ch[i].resize(0);
    }
}
