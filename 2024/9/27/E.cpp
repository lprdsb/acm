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

#define maxn 600000
int T, n;
pair<int, int> pa[maxn + 5];

int as[maxn + 5], fa[maxn + 5], a[maxn + 5];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
int chk(int x) {
    if(as[x] != -1) return as[x];
    For(i, 1, 2 * n) fa[i] = i, a[i] = 0;
    int cnt = 0, now = 0, lim = 0;
    as[x] = 0;
    For(i, 1, n) if(pa[i].fir > lim) {
        For(j, now + 1, pa[i].sec - 1) fa[j] = now;
        a[pa[i].sec]++; cnt++;
        int to = find(pa[i].fir - 1);
        if(to) {
            if(to > lim) cnt--;
            a[to]--;
            if(!a[to]) fa[to] = find(to - 1);
        }
        now = pa[i].sec;
        // cout << i << " " << cnt << endl;
        if(cnt == x) {
            as[x]++;
            cnt = 0;
            lim = now;
        }
    }
    return as[x];
}

void sol(int l, int r) {
    if(l == r) {
        as[l] = chk(l);
        return;
    }
    if(chk(l) == chk(r)) {
        For(i, l, r) as[i] = chk(l);
        return;
    }
    int md = l + r >> 1;
    if(chk(md) != chk(l)) sol(l, md);
    else For(i, l, md) as[i] = chk(l);
    if(chk(md + 1) != chk(r)) sol(md + 1, r);
    else For(i, md + 1, r) as[i] = chk(r);
}

void mian() {
    read(n);
    For(i, 1, n) read(pa[i].fir);
    For(i, 1, n) read(pa[i].sec);
    sort(pa + 1, pa + n + 1, [](cst pair<int, int> &x, cst pair<int, int> &y) {return x.sec < y.sec;});
    For(i, 1, n) as[i] = -1;
    // cout << chk(3) << endl;
    sol(1, n);
    int res = 0;
    For(i, 1, n) res = max(res, i * as[i]);
    printf("%d\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
