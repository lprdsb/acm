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
int T, n, m, fa[maxn + 5], cnt = 0;

pair<int, pair<int, int> > pa[maxn + 5];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void mian() {
    read(n); read(m);
    cnt = n;
    For(i, 1, m) {
        int u, v, w; read(u); read(v); read(w);
        pa[i] = { w, {u, v} };
    }
    sort(pa + 1, pa + m + 1);
    For(i, 1, n) fa[i] = i;
    For(i, 1, m) {
        auto [w, e] = pa[i];
        auto [u, v] = e;
        if(find(u) != find(v)) {
            fa[find(u)] = find(v);
            cnt--;
            if(cnt == 1) {
                printf("%d\n", w);
                return;
            }
        }
    }
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
