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
int T, n, a[maxn + 5], fa[maxn + 5], sz[maxn + 5], type[maxn + 5];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int chk(int x) {
    if(!type[x]) return 0;
    if(sz[x] % 2 == 0) return 1;
    if(type[x] & 1) return 1;
    return 0;
}

int vis[maxn + 5], ok = 0, sum = 0;
void mer(int x) {
    vis[x] = 1;
    if(x != n && vis[x + 1]) {
        ok -= chk(x + 1);
        sum -= (sz[x + 1] + 1) / 2;
        sz[x] += sz[x + 1];
        if(type[x + 1] & 2) type[x] |= 1;
        if(type[x + 1] & 1) type[x] |= 2;
        fa[x + 1] = x;
    }
    if(x != 1 && vis[x - 1]) {
        int tt = find(x - 1);
        ok -= chk(tt);
        sum -= (sz[tt] + 1) / 2;
        if(sz[tt] % 2 == 0) type[tt] |= type[x];
        else {
            if(type[x] & 2) type[tt] |= 1;
            if(type[x] & 1) type[tt] |= 2;
        }
        sz[tt] += sz[x];
        fa[x] = tt;
    }
    sum += (sz[find(x)] + 1) / 2;
    // if(x == 2) cout << type[x] << endl;
    ok += chk(find(x));
}

void mian() {
    read(n);
    For(i, 1, n + 1) {
        fa[i] = i;
        vis[i] = 0;
        sz[i] = 1;
        type[i] = 0;
    }
    int mx = 0;
    For(i, 1, n) read(a[i]), mx = max(mx, a[i]);
    set<pair<int, int> > se;
    For(i, 1, n) se.insert({ -a[i], i });
    int res = 0;
    ok = 0; sum = 0;
    for(auto [v, p] : se) {
        if(a[p] == mx) {
            type[p] = 1;
        }
        // if(p == 2) cout << mx << endl;
        mer(p);
        // cout << p << " " << ok << endl;
        res = max(res, sum + mx - v - (ok == 0));
    }

    For(i, 1, n + 1) {
        fa[i] = i;
        vis[i] = 0;
        sz[i] = 1;
        type[i] = 0;
    }
    For(i, 1, n) if(a[i] == mx) a[i]--;
    mx--;
    se.clear();
    For(i, 1, n) se.insert({ -a[i], i });
    ok = 0; sum = 0;
    for(auto [v, p] : se) {
        if(a[p] == mx) {
            type[p] = 1;
        }
        mer(p);
        res = max(res, sum + mx - v - (ok == 0));
    }

    cout << res << endl;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
