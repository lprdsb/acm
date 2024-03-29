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

#define maxn 1000000
int T, n, q, a[maxn + 5], pos[maxn + 5];
vector<pair<int, int> > vec[maxn + 5];

LL tr[maxn + 5], f[maxn + 5];
void ins(int x, LL y) {
    while(x <= n) tr[x] += y, x += x & -x;
}
LL que(int x) {
    LL res = 0;
    while(x) res += tr[x], x -= x & -x;
    return res;
}

LL as[maxn + 5];
void mian() {
    read(n); read(q);
    For(i, 1, n) tr[i] = 0, vec[i].resize(0);
    For(i, 1, n) read(a[i]), pos[a[i]] = i;
    For(i, 1, q) {
        int l, r; read(l); read(r);
        vec[l].pb({ i, r });
    }
    Rof(i, n, 1) {
        vector<int> tem;
        For(j, 2, n / a[i]) if(pos[a[i] * j] >= i) tem.pb(pos[a[i] * j]);
        sort(tem.begin(), tem.end());
        ins(i, 1);
        for(auto j : tem) {
            f[j] += 1;
            ins(j, f[j]);
            For(p, 2, n / a[j]) if(pos[a[j] * p] >= j) f[pos[a[j] * p]] += f[j];
            f[j] = 0;
        }
        // for(auto j : tem) f[j] = 0;
        for(auto i : vec[i]) as[i.fir] = que(i.sec);
    }
    For(i, 1, q) printf("%lld ", as[i]);
    puts("");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
