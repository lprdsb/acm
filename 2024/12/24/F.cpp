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
int T, n, ch[maxn + 5][2], st[maxn + 5];
LL a[maxn + 5], b[maxn + 5], f[maxn + 5][105], g[105];

void dfs(int u) {
    // cout << u << endl;
    For(i, 0, 100) f[u][i] = Inf;
    f[u][0] = a[u];
    For(o, 0, 1) if(ch[u][o]) {
        int v = ch[u][o];
        dfs(v);
        int now = 0;
        For(i, 0, 100) g[i] = Inf;
        For(i, 0, 100) {
            while(now <= i && f[v][now] >= f[u][i - now]) now++;
            For(o, -1, 1) if(i >= now + o && now + o >= 0) g[i] = min(g[i], max(f[v][now + o], f[u][i - now - o]));
        }
        For(i, 0, 100) f[u][i] = g[i];
    }
    // For(i, 0, 100) f[u][i] = max(f[u][i], a[u]);
    For(i, 0, 99) f[u][i + 1] = min(f[u][i + 1], (f[u][i] + b[u] - 1) / b[u]);
    // if(u == 1) {
    //     cout << u << " " << f[u][0] << endl;
    // }
}

void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) read(b[i]);
    For(i, 1, n) For(o, 0, 1) ch[i][o] = 0;
    int tp = 0;
    For(i, 1, n) {
        while(tp && b[st[tp]] > b[i]) {
            if(tp && b[st[tp - 1]] > b[i]) ch[st[tp - 1]][1] = st[tp];
            else ch[i][0] = st[tp];
            tp--;
        }
        st[++tp] = i;
    }
    // cout << ch[3][0] << endl;
    while(tp) ch[st[tp - 1]][1] = st[tp], tp--;
    dfs(st[1]);
    For(i, 0, 100) if(f[st[1]][i] == 1) {
        printf("%d\n", i);
        return;
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
