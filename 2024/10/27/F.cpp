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
int T, n, m, a[maxn + 5][maxn + 5];
int tot = 0;
int dis[maxn * maxn + 5], ok[2][maxn + 5][2];

void mian() {
    read(n); read(m);
    tot = n * m;
    For(i, 0, n - 1) For(j, 0, m - 1) read(a[i][j]);
    queue<int> q;
    dis[0] = 1;
    q.push(0);
    while(q.size()) {
        int u = q.front(); q.pop();
        int x = u / m, y = u % m;
        if(!ok[0][x][a[x][y]]) {
            For(i, 0, m - 1) if(a[x][y] == a[x][i] && !dis[x * m + i]) {
                dis[x * m + i] = dis[u] + 1;
                q.push(x * m + i);
            }
            ok[0][x][a[x][y]] = 1;
        }
        if(!ok[1][y][a[x][y]]) {
            For(i, 0, n - 1) if(a[x][y] != a[i][y] && !dis[i * m + y]) {
                dis[i * m + y] = dis[u] + 1;
                q.push(i * m + y);
            }
            ok[1][y][a[x][y]] = 1;
        }
    }
    printf("%d\n", dis[n * m - 1] - 1);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 0, tot) {
            dis[i] = 0;
        }
        For(i, 0, n) For(o, 0, 1) ok[0][i][o] = 0;
        For(i, 0, m) For(o, 0, 1) ok[1][i][o] = 0;
    }
}
