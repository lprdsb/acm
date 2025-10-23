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
int T, n, a[maxn + 5], tot, f[maxn + 5];
pair<int, int> pa[maxn + 5];

int tr[maxn + 5];
void ins(int x, int y) {
    while(x <= tot) tr[x] = max(tr[x], y), x += x & -x;
}
int que(int x) {
    int res = -inf;
    while(x) res = max(res, tr[x]), x -= x & -x;
    return res;
}

void mian() {
    read(n);
    For(i, 1, n) read(pa[i].fir), read(pa[i].sec);
    sort(pa + 1, pa + n + 1);
    vector<int> b;
    b.pb(0);
    For(i, 1, n) b.pb(pa[i].sec - pa[i].fir);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    tot = b.size() + 1;
    For(i, 0, n) a[i] = lower_bound(b.begin(), b.end(), pa[i].sec - pa[i].fir) - b.begin() + 1;
    f[0] = 0;
    ins(a[0], f[0]);
    For(i, 1, n) {
        f[i] = que(a[i]) + 1;
        ins(a[i], f[i]);
    }
    int res = 0;
    For(i, 1, n) res = max(res, f[i]);
    printf("%d\n", res);
}

int main() {
    //freopen("in", "r", stdin);
    memset(tr, -inf, sizeof tr);
    read(T);
    while(T--) {
        mian();
        For(i, 0, tot) tr[i] = -inf;
    }
}
