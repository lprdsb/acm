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

#define maxn 20
int T, n, a[maxn + 5][maxn + 5], b[maxn + 5][maxn + 5], B = 18, BB = 18;

vector<LL> vec[maxn + 5];

void dfs1(int nx, int ny, LL mask) {
    if(nx + ny == B) {
        vec[nx].pb(mask);
        return;
    }
    if(nx <= n) {
        dfs1(nx + 1, ny, mask);
        dfs1(nx + 1, ny, mask | (1ll << a[nx][ny]));
    }
    if(ny <= n) {
        dfs1(nx, ny + 1, mask);
        dfs1(nx, ny + 1, mask | (1ll << b[nx][ny]));
    }
}

int mex = 0;
void dfs2(int nx, int ny, LL mask) {
    if(nx + ny == B) {
        while(666) {
            LL all = (1ll << (mex + 1)) - 1;
            if(binary_search(vec[nx].begin(), vec[nx].end(), all ^ (all & mask))) mex++;
            else break;
        }
        return;
    }
    if(nx > 1) dfs2(nx - 1, ny, mask | (1ll << a[nx - 1][ny]));
    if(ny > 1) dfs2(nx, ny - 1, mask | (1ll << b[nx][ny - 1]));
}

void mian() {
    read(n);
    For(i, 1, n - 1) For(j, 1, n) read(a[i][j]);
    For(i, 1, n) For(j, 1, n - 1) read(b[i][j]);
    B = max(2, n * 2 / 3);
    dfs1(1, 1, 0);
    For(i, 1, n) {
        sort(vec[i].begin(), vec[i].end());
        vec[i].erase(unique(vec[i].begin(), vec[i].end()), vec[i].end());
    }
    mex = 0;
    dfs2(n, n, 0);
    printf("%d\n", mex);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) vec[i].resize(0);
    }
}
