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

#define maxn 400000

int n, q, cnt = 0;
LL a[maxn + 5], aa[maxn + 5];

vector<LL> b;
pair<int, int> opt[maxn + 5];

int tr[maxn + 5];
void ins(int x, int y) {
    while(x <= cnt) tr[x] += y, x += x & -x;
}
int que(int x) {
    int res = 0;
    while(x) res += tr[x], x -= x & -x;
    return res;
}
int find(int x) {
    int res = 0;
    Rof(o, 20, 0) {
        int to = res + (1 << o);
        if(to <= cnt && x >= tr[to]) {
            x -= tr[to];
            res = to;
        }
    }
    return res;
}

int T;

void mian() {
    read(n); read(q);
    For(i, 1, n) read(a[i]), aa[i] = a[i], b.pb(a[i]);
    For(i, 1, n) aa[i] = a[i];
    For(i, 1, q) {
        int p, v; read(p); read(v);
        opt[i] = { p, v };
        aa[p] += v;
        b.pb(aa[p]);
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    cnt = b.size();
    For(i, 1, n) ins(lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1, 1);
    For(i, 1, q) {
        auto [p, v] = opt[i];
        int k = lower_bound(b.begin(), b.end(), a[p]) - b.begin() + 1;
        ins(k, -1);
        a[p] += v;
        k = lower_bound(b.begin(), b.end(), a[p]) - b.begin() + 1;
        ins(k, 1);
        int res = find((n + 1) / 2);
        printf("%d\n", que(res));
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        b.clear();
        For(i, 0, cnt) tr[i] = 0;
    }
}