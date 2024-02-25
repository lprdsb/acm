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
int T, n, m, ma[maxn + 5][maxn + 5];
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

bool chk(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && !ma[x][y];
}

int vis[maxn + 5][maxn + 5], sx, sy, tot = 0;
namespace c1 {
    void mian() { printf("%d\n", n * m - tot - 1); }
}
namespace c2 {
    void mian() {
        int res = inf;
        For(i, 0, m - 1) {
            if(!ma[0][i]) res = min(res, vis[0][i]);
            if(!ma[n - 1][i]) res = min(res, vis[n - 1][i]);
        }
        For(i, 0, n - 1) {
            if(!ma[i][0]) res = min(res, vis[i][0]);
            if(!ma[i][m - 1]) res = min(res, vis[i][m - 1]);
        }
        // cout << res << endl;
        printf("%d\n", n * m - tot - res);
    }
}
namespace c3 {
    pair<int, int> dis[maxn + 5][maxn + 5][2];
    void mian() {
        For(i, 0, n - 1) For(j, 0, m - 1) For(o, 0, 1) dis[i][j][o] = { inf, inf };
        queue<int> q;
        For(i, 0, m - 1) {
            if(!ma[0][i]) {
                dis[0][i][0] = { 1, i };
                q.push(i);
            }
            if(!ma[n - 1][i]) {
                dis[n - 1][i][0] = { 1, (n - 1) * m + i };
                q.push((n - 1) * m + i);
            }
        }
        For(i, 0, n - 1) {
            if(!ma[i][0]) {
                dis[i][0][0] = { 1, i * m };
                q.push(i * m);
            }
            if(!ma[i][m - 1]) {
                dis[i][m - 1][0] = { 1, i * m + m - 1 };
                q.push(i * m + m - 1);
            }
        }
        while(q.size()) {
            int u = q.front(); q.pop();
            int x = u / m, y = u % m;
            For(o, 0, 3) {
                int tx = x + dir[o][0], ty = y + dir[o][1];
                if(!chk(tx, ty)) continue;
                pair<int, int> tem = dis[x][y][0];
                tem.fir++;
                if(tem.fir < dis[tx][ty][0].fir) dis[tx][ty][0] = tem, q.push(tx * m + ty);
                else if(tem.sec != dis[tx][ty][0].sec && tem.fir < dis[tx][ty][1].fir) dis[tx][ty][1] = tem, q.push(tx * m + ty);
                tem = dis[x][y][1];
                tem.fir++;
                if(tem.sec != dis[tx][ty][0].sec && tem.fir < dis[tx][ty][1].fir) dis[tx][ty][1] = tem, q.push(tx * m + ty);
            }
        }
        // cout << dis[1][2][0].fir << endl;
        LL res = Inf;
        For(i, 0, n - 1) For(j, 0, m - 1) if(!ma[i][j]) res = min(res, 1ll * dis[i][j][0].fir + dis[i][j][1].fir - 2 + vis[i][j]);
        printf("%lld\n", n * m - res - tot);
    }
}

void mian() {
    read(n); read(m);
    For(i, 0, n - 1) For(j, 0, m - 1) {
        char c; cin >> c;
        if(c == '#') ma[i][j] = 1, tot++;
        if(c == 'V') sx = i, sy = j;
    }
    int cnt = 0;
    queue<int> q;
    q.push(sx * m + sy);
    vis[sx][sy] = 1;
    while(q.size()) {
        int u = q.front(); q.pop();
        int x = u / m, y = u % m;
        if(x == 0 || x == n - 1 || y == 0 || y == m - 1) cnt++;
        For(o, 0, 3) {
            int tx = x + dir[o][0], ty = y + dir[o][1];
            if(!chk(tx, ty) || vis[tx][ty] != inf) continue;
            vis[tx][ty] = vis[x][y] + 1;
            q.push(tx * m + ty);
        }
    }
    if(!cnt) c1::mian();
    else if(cnt == 1) c2::mian();
    else c3::mian();
}

int main() {
    // freopen("in.txt", "r", stdin);
    memset(vis, inf, sizeof vis);
    read(T);
    while(T--) {
        mian();
        tot = 0;
        For(i, 0, n - 1) For(j, 0, m - 1) {
            vis[i][j] = inf;
            ma[i][j] = 0;
        }
    }
}
