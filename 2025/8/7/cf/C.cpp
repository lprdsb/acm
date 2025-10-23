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
int T, n, k, a[maxn + 5], b[maxn + 5];
vector<int> vec;

LL tr[2][2 * maxn + 5];
void ins(int o, int x, LL y) {
    x++;
    if(o) x = vec.size() - x + 1;
    while(x <= vec.size()) tr[o][x] = min(tr[o][x], y), x += x & -x;
}
LL que(int o, int x) {
    x++;
    if(o) x = vec.size() - x + 1;
    LL res = Inf;
    while(x) res = min(res, tr[o][x]), x -= x & -x;
    return res;
}

int id[maxn + 5];

void mian() {
    read(n); read(k);
    For(i, 1, n) read(a[i]), vec.pb(a[i]);
    For(i, 1, n) read(b[i]), vec.pb(b[i]);
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    For(i, 1, n) a[i] = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin();
    For(i, 1, n) b[i] = lower_bound(vec.begin(), vec.end(), b[i]) - vec.begin();
    For(i, 1, n) if(a[i] > b[i]) swap(a[i], b[i]);
    For(i, 1, n) id[i] = i;
    sort(id + 1, id + n + 1, [](int x, int y) {return a[x] < a[y];});
    LL mn = Inf;
    LL sum = 0;
    Rof(i, n, 1) {
        int tmp = abs(vec[a[id[i]]] - vec[b[id[i]]]);
        sum += tmp;
    }
    For(i, 1, n - 1) {
        int t1 = abs(vec[a[id[i]]] - vec[b[id[i]]]), t2 = abs(vec[a[id[i + 1]]] - vec[b[id[i + 1]]]);
        mn = min(mn, max(0ll, 1ll * vec[b[id[i + 1]]] - vec[a[id[i]]] + vec[a[id[i + 1]]] - vec[b[id[i]]] - t1 - t2));
    }
    // cout << mn << endl;
    mn = max(0ll, mn);
    printf("%lld\n", sum + mn);
}

int main() {
    // cout << inf << endl;
    // freopen("in.txt", "r", stdin);
    For(o, 0, 1) For(i, 0, 2 * maxn) tr[o][i] = Inf;
    read(T);
    while(T--) {
        mian();
        For(i, 0, vec.size()) tr[0][i] = tr[1][i] = Inf;
        vec.resize(0);
    }
}
