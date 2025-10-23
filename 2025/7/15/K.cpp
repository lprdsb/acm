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
int n, ch[maxn + 5][5], d[maxn + 5];

int f[maxn + 5][5];

int tot = 0;
map<pair<int, int>, int> ma;

int vis[maxn + 5][5], tp = 0, vise[5 * maxn + 5];
int dfs(int x, int o) {
    if(f[x][o] != -1) return f[x][o];
    vis[x][o] = 1;
    int to = ch[x][o];
    int tmp = -1;
    For(o, 1, d[to]) if(ch[to][o] == x) {
        tmp = o;
        break;
    }
    int id = ma[{x, to}];
    int res = 0;
    tmp = tmp % d[to] + 1;
    if(vis[to][tmp]) {
        res = tp + (!vise[id]);
    }
    else {
        int flag = 0;
        if(!vise[id]) {
            tp++;
            vise[id] = 1;
            flag = 1;
        }
        res = dfs(to, tmp);
        if(flag == 1) {
            vise[id] = 0;
        }
    }
    return f[x][o] = res;
}


int main() {
    // freopen("in.txt", "r", stdin);
    memset(f, -1, sizeof f);
    read(n);
    For(i, 1, n) {
        read(d[i]);
        For(j, 1, d[i]) {
            read(ch[i][j]);
            if(!ma.count({ i, ch[i][j] })) {
                tot++;
                ma[{i, ch[i][j]}] = tot;
                ma[{ch[i][j], i}] = tot;
            }
        }
    }
    For(i, 1, n) {
        tp = 0;
        printf("%d\n", dfs(i, 1));
    }
    return 0;
}
