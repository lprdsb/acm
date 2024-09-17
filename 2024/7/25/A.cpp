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

#define maxn 1000000
int n, T;

int fa[maxn + 5], dis[maxn + 5], mx[maxn + 5];
int find(int x) {
    if(fa[x] == x) return x;
    int ffa = find(fa[x]);
    dis[x] += dis[fa[x]];
    return fa[x] = ffa;
}

void mian() {
    read(n);
    For(i, 1, n) fa[i] = i, dis[i] = 0, mx[i] = 0;
    For(i, 1, n - 1) {
        int u, v, c; read(u); read(v); read(c);
        // cout << mx[1] << endl;
        int uu = find(u);
        mx[uu] = max(mx[uu], mx[v] + dis[u] + 1);
        fa[v] = find(u);
        dis[v] = dis[u] + 1;
        printf("%d ", mx[c]);
    }
    puts("");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
