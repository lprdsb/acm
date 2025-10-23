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

#define maxn 1000000
int n, m, s, t;
vector<int> ch[maxn + 5];

int dis[maxn + 5];
int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(m);
    For(i, 1, m) {
        int u, v; read(u); read(v); u--; v--;
        ch[u].pb(n + v);
        ch[n + u].pb(2 * n + v);
        ch[2 * n + u].pb(v);
    }
    read(s); read(t); s--; t--;
    queue<int> q;
    q.push(s);
    dis[s] = 1;
    while(q.size()) {
        int u = q.front(); q.pop();
        for(auto v : ch[u]) if(!dis[v]) {
            dis[v] = dis[u] + 1;
            if(v == t) {
                printf("%d\n", (dis[v] - 1) / 3);
                return 0;
            }
            q.push(v);
        }
    }
    puts("-1");
    return 0;
}
