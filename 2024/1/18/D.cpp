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
int T, n, fa[2][maxn + 5], a[maxn + 5], d[maxn + 5];

int find(int ty, int x) { return fa[ty][x] == x ? x : fa[ty][x] = find(ty, fa[ty][x]); }

int res = 0;
vector<int> vec[2];
void del(int x) {
    if(!x || x > n || find(0, x) != x) return;
    int l = find(0, x - 1), r = find(1, x + 1);
    if(l) vec[1].pb(l);
    if(r <= n) vec[1].pb(r);
    fa[0][x] = l;
    fa[1][x] = r;
    // cout << x << endl;
    res++;
}

void ins(int x) {
    // cout << x << endl;
    int l = find(0, x - 1), r = find(1, x + 1);
    if(a[l] + a[r] > d[x]) vec[0].pb(x);
}

void mian() {
    read(n);
    For(i, 0, n + 1) For(o, 0, 1) fa[o][i] = i;
    For(i, 1, n) read(a[i]); a[n + 1] = 0;
    For(i, 1, n) read(d[i]);
    For(i, 1, n) vec[1].pb(i);
    // res = n;
    For(o, 1, n) {
        // cout << o << "asd" << endl;
        for(auto i : vec[1]) ins(i);
        vec[1].resize(0);
        res = 0;
        for(auto i : vec[0]) del(i);
        vec[0].resize(0);
        printf("%d ", res);
    }
    puts("");
    return;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
