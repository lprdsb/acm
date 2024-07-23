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
int T, n, a[maxn + 5], vis[maxn + 5], fa[maxn + 5];
vector<pair<int, int> > as;

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) fa[i] = i;
    Rof(i, n - 1, 1) {
        int fl = 0;
        For(j, 0, i - 1) vis[j] = 0;
        For(j, 1, n) {
            if(vis[a[j] % i] && find(vis[a[j] % i]) != find(j)) {
                as.pb({ vis[a[j] % i], j });
                fa[find(j)] = find(vis[a[j] % i]);
                // if(i == 3) cout << j << endl;
                fl = 1;
                break;
            }
            vis[a[j] % i] = j;
        }
        if(!fl) {
            puts("NO");
            return;
        }
    }
    puts("YES");
    reverse(as.begin(), as.end());
    for(auto [u, v] : as) printf("%d %d\n", u, v);
    as.resize(0);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
