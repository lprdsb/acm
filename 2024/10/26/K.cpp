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

#define maxn 100000
LL n, a[maxn + 5], v[maxn + 5], b[maxn + 5], id[maxn + 5];
LL m, sb[maxn + 5], sbv[maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(m);
    LL as = 0;
    LL res = 0;
    For(i, 1, n) {
        LL w, l, r; read(w); read(l); read(r);
        res += w * l;
        b[i] = l;
        a[i] = r - l;
        v[i] = w;
        m -= l;
    }
    // For(i, 1, n) as = max(as, (m - sl) * v[i] + res);
    For(i, 1, n) id[i] = i;
    sort(id + 1, id + n + 1, [](int x, int y) {return v[x] > v[y];});
    For(i, 1, n) {
        sb[i] = sb[i - 1] + a[id[i]];
        sbv[i] = sbv[i - 1] + a[id[i]] * v[id[i]];
    }
    For(i, 1, n) {
        if(m + b[id[i]] >= sb[i - 1]) as = max(as, res + sbv[i - 1] + (m - sb[i - 1]) * v[id[i]]);
        else {
            int l = 1, r = i - 1;
            while(l < r) {
                int md = l + r >> 1;
                if(sb[md] > m + b[id[i]]) r = md;
                else l = md + 1;
            }
            as = max(as, res + sbv[l - 1] - b[id[i]] * v[id[i]] + (m + b[id[i]] - sb[l - 1]) * v[id[l]]);
        }
        // cout << as << " " << a[id[i]] << " " << v[id[i]] << endl;
    }
    printf("%lld\n", as);
    return 0;
}
