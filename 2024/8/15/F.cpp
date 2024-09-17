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

#define maxn 1000
int n, a[maxn + 5][maxn + 5], stk[2 * maxn + 5], tp = 0;
int vis[maxn + 5][maxn + 5], tot = 0, as[maxn * maxn + 5];

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

int id[maxn * maxn + 5][2], gc[maxn + 5][maxn + 5], cnt[maxn + 5];

int get_gc(int x, int y) {
    return gc[abs(x)][abs(y)];
}

void mian() {
    read(n);
    For(i, 1, n * n) {
        int x, y; read(x); read(y);
        a[x][y] = i;
        id[i][0] = x; id[i][1] = y;
    }
    For(i, 0, n) For(j, 0, n) gc[i][j] = gcd(i, j);
    For(i, 1, n * n) if(!vis[id[i][0]][id[i][1]]) {
        // cout << i << endl;
        vector<pair<int, int> > v;
        For(j, 1, tp) {
            int dx = id[i][0] - id[stk[j]][0], dy = id[i][1] - id[stk[j]][1], gc = get_gc(dx, dy);
            dx /= gc; dy /= gc;
            if(dx < 0) dx = -dx, dy = -dy;
            int nx = id[i][0], ny = id[i][1];
            while(nx > dx && ny > dy && ny - dy <= n) nx -= dx, ny -= dy;
            while(nx <= n && nx >= 1 && ny <= n && ny >= 1) {
                vis[nx][ny] = 1;
                nx += dx; ny += dy;
            }
        }
        stk[++tp] = i;
        as[i] = 1;
    }
    For(i, 1, n * n) printf("%d", as[i]);
    return;
}

int main() {
    // freopen("in.txt", "r", stdin);
    mian();
}