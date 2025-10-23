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

#define maxn 2000
int T, n, x, a[maxn + 5], num[maxn + 5];

vector<int> ch[maxn + 5];

LL dfs(LL val, int u, int pre) {
    LL tmp = a[u];
    for(auto v : ch[u]) if(v != pre) tmp += dfs(val, v, u);
    val += num[u];
    // if(val == 24) cout << u << " " << tmp << " " << val << endl;
    if(val > tmp) return (val - tmp) & 1;
    return tmp - val;
}

void mian() {
    read(n); read(x);
    LL sum = 0;
    For(i, 1, n) read(a[i]), sum += a[i];
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v);
        ch[v].pb(u);
    }
    LL res = Inf;
    For(i, 0, 2 * n - 1) {
        if((i + sum) % 2 == 0) {
            LL l = 0, r = inf;
            while(l < r) {
                LL md = l + r >> 1;
                if(!dfs(2 * md, x, 0)) r = md;
                else l = md + 1;
            }
            res = min(res, i + 2ll * l * n);
        }
        num[i % n + 1]++;
    }
    printf("%lld\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) {
            ch[i].resize(0);
            num[i] = 0;
        }
    }
}
