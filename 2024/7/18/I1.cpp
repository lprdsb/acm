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

#define maxn 6000
int n, a[maxn + 5], L[maxn + 5], R[maxn + 5];
int id[maxn + 5];
vector<int> ch[maxn + 5];

LL f[maxn + 5], g[maxn + 5];
int main() {
    // freopen("in.txt", "r", stdin);
    read(n); int len = n * 2;
    L[0] = 0; R[0] = 2 * n + 1;
    For(i, 1, 2 * n) read(a[i]);
    For(i, 1, len) R[a[i]] = i;
    Rof(i, len, 1) L[a[i]] = i;
    For(i, 0, n) id[i] = i;
    sort(id, id + n + 1, [](const int &x, const int &y) {return R[x] - L[x] < R[y] - L[y];});
    For(i, 0, n) For(j, 0, n) if(L[i] < L[j] && R[i] > R[j]) ch[i].pb(j);
    For(i, 0, n) {
        LL now = 0;
        For(j, L[id[i]] + 1, R[id[i]] - 1) {
            if(R[a[j]] < R[id[i]] && L[a[j]] == j) f[R[a[j]]] = max(f[R[a[j]]], now + g[a[j]] - 1ll * (R[a[j]] - L[a[j]] + 1) * id[i]);
            now = max(now, f[j]);
        }
        g[id[i]] = now + 1ll * (R[id[i]] - L[id[i]] + 1) * id[i];
        For(j, L[id[i]] + 1, R[id[i]] - 1) f[j] = 0;
    }
    // cout << g[1] << endl;
    printf("%lld\n", g[0]);
    return 0;
}
