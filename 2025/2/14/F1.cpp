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
int n, m, a[maxn + 5][maxn + 5], dis[maxn + 5][maxn + 5];
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int cnt = 0;
pair<int, int> poi[maxn * maxn + 5];

struct Node {
    int d, x, y, sx, sy;
};
bool operator < (cst Node &x, cst Node &y) {
    return x.d > y.d;
}

int main() {
    //freopen("in", "r", stdin);
    read(n); read(m);
    priority_queue<Node> q;
    memset(dis, inf, sizeof dis);
    For(i, 0, n) For(j, 0, m) {
        char c; cin >> c;
        a[i][j] = c - '0';
        if(a[i][j]) q.push({ 0, i, j, i, j }), dis[i][j] = 0;
    }
    while(q.size()) {
        auto [d, x, y, sx, sy] = q.top(); q.pop();
        For(o, 0, 3) {
            int tx = x + dir[o][0], ty = y + dir[o][1];
            if(tx >= 0 && tx <= n && ty >= 0 && ty <= m) {
                int tmp = (tx - sx) * (tx - sx) + (ty - sy) * (ty - sy);
                if(dis[tx][ty] > tmp) {
                    dis[tx][ty] = tmp;
                    q.push({ tmp, tx, ty, sx, sy });
                }
            }
        }
    }
    LL res = 0;
    For(i, 0, n) For(j, 0, m) res += dis[i][j];
    cout << res << endl;
}