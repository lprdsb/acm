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
int n, q, id[maxn + 5], ch[2 * maxn + 5][2], tot = 0;

int dfn[2 * maxn + 5], tim = 0;
void dfs(int u) {
    dfn[u] = ++tot;
    For(o, 0, 1) if(ch[u][o]) dfs(ch[u][o]);
}

int b[2 * maxn + 5], cnt = 0, L[maxn + 5], R[maxn + 5], sum[maxn + 5], vis[maxn + 5];
#define mod 998244353
int main() {
    //freopen("in", "r", stdin);
    read(n); read(q); id[n] = ++tot;
    For(i, 1, q) read(L[i]);
    For(i, 1, q) read(R[i]);
    For(i, 1, q) {
        int l = L[i], r = R[i]; b[++cnt] = l; b[++cnt] = r; vis[l] = vis[r] = 1;
        if(l > r) {
            ch[id[l]][0] = ++tot;
            ch[id[l]][1] = ++tot;
        }
        else {
            ch[id[r]][0] = ++tot;
            ch[id[r]][1] = ++tot;
        }
        id[l] = tot - 1; id[r] = tot;
    }
    dfs(1);
    sort(b + 1, b + cnt + 1);
    cnt = unique(b + 1, b + cnt + 1) - b - 1;
    sort(b + 1, b + cnt + 1, [](int x, int y) {return dfn[id[x]] < dfn[id[y]];});
    // For(i, 1, cnt) cout << b[i] << " "; cout << endl;
    b[cnt + 1] = 0;
    For(i, 0, cnt) sum[max(b[i], b[i + 1])]++;
    int now = cnt + 1, res = 1;
    For(i, 1, n) now -= sum[i];
    Rof(i, n, 1) {
        if(!vis[i]) {
            res = 1ll * res * now % mod;
            now++;
        }
        now += sum[i];
    }
    printf("%d\n", res);
}
