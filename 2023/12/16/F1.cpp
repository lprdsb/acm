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

#define maxn 200000
int T, n, a[maxn + 5], mn[maxn + 5][2], mx[maxn + 5][2];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

map<int, map<int, int> > ma;
void solve() {
    read(n);
    For(i, 1, n) read(a[i]);
    int cnt = 0;
    For(i, 1, n) {
        For(o, 0, 1) mx[i][o] = mx[i - 1][o];
        int tem = i;
        For(o, 0, 1) if(mx[i][o] == -1 || a[tem] > a[mx[i][o]]) swap(tem, mx[i][o]);
    }
    Rof(i, n, 1) {
        For(o, 0, 1) mn[i][o] = mn[i + 1][o];
        int tem = i;
        For(o, 0, 1) if(mn[i][o] == -1 || a[tem] < a[mn[i][o]]) swap(tem, mn[i][o]);
    }
    For(i, 1, n) cnt += mx[i][0] == i && mn[i][0] == i;
    For(i, 1, n) {
        if(mx[i - 1][0] != -1 && a[mx[i - 1][0]] > a[i] && (mx[i - 1][1] == -1 || a[mx[i - 1][1]] < a[i])
            && mn[i + 1][0] != -1 && a[mn[i + 1][0]] < a[i] && (mn[i + 1][1] == -1 || a[mn[i + 1][1]] > a[i])) ma[mx[i - 1][0]][mn[i + 1][0]]++;
        if(a[i] > i && (mn[a[i] + 1][0] == -1 || a[mn[a[i] + 1][0]] > a[i])) ma[i][a[i]]++;
        if(a[i] < i && (mx[a[i] - 1][0] == -1 || a[mx[a[i] - 1][0]] < a[i])) ma[a[i]][i]++;
    }
    int res = -2;
    for(auto [k1, v1] : ma) for(auto [k2, v2] : v1) res = max(res, v2);
    printf("%d\n", cnt + res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    int *p;
    memset(mn, -1, sizeof mn);
    memset(mx, -1, sizeof mx);
    read(T);
    while(T--) {
        solve();
        For(i, 1, n) For(o, 0, 1) mn[i][o] = mx[i][o] = -1;
        ma.clear();
    }
}
