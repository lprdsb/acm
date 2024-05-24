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
int n, a[maxn + 5], L[maxn + 5], R[maxn + 5], to[maxn + 5];
vector<int> vec[maxn + 5];

int tr[maxn + 5];
void ins(int x, int y) {
    while(x <= maxn) tr[x] = max(tr[x], y), x += x & -x;
}
int que(int x) {
    int res = 0;
    while(x) res = max(res, tr[x]), x -= x & -x;
    return res;
}

int vis[maxn + 5];
int main() {
    // freopen("in.txt", "r", stdin);
    read(n);
    For(i, 1, n) L[i] = inf, R[i] = -inf;
    For(i, 1, n) {
        read(a[i]);
        vis[a[i]] = 1;
    }
    For(i, 1, n) R[a[i]] = i;
    Rof(i, n, 1) L[a[i]] = i;
    For(i, 1, n) if(vis[i]) {
        to[L[i]] = max(to[L[i]], R[i]);
        vec[L[i]].pb(i);
    }
    int now = 0;
    vector<int> vv;
    For(i, 1, n + 1) {
        if(i > now) {
            sort(vv.begin(), vv.end());
            reverse(vv.begin(), vv.end());
            for(auto k : vv) ins(k, que(k) + 1);
            vv.resize(0);
        }
        for(auto k : vec[i]) vv.pb(k);
        now = max(now, to[i]);
    }
    int res = 0;
    For(i, 1, n) if(vis[i]) res++;
    printf("%d\n", res - que(n));
    return 0;
}
