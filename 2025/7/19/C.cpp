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
int T, n, a[maxn + 5], b[maxn + 5], id[maxn + 5], id1[maxn + 5], vis[maxn + 5];

void mian() {
    read(n);
    For(i, 1, n) read(a[i]), read(b[i]);
    For(i, 1, n) id[i] = id1[i] = i;
    sort(id + 1, id + n + 1, [](int x, int y) {return a[x] < a[y];});
    sort(id1 + 1, id1 + n + 1, [](int x, int y) {return b[x] < b[y];});
    For(i, 1, n / 2) vis[id1[i]] = 0;
    For(i, n / 2 + 1, n) vis[id1[i]] = 1;
    vector<int> vec[2];
    For(i, 1, n / 2) vec[vis[id[i]]].pb(id[i]);
    LL res = 0;
    For(i, n / 2 + 1, n) {
        int to = vec[!vis[id[i]]].back(); vec[!vis[id[i]]].pop_back();
        printf("%d %d\n", id[i], to);
        res += abs(a[id[i]] - a[to]) + abs(b[id[i]] - b[to]);
    }
    // cout << res << endl;
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
