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

#define maxn 100000
int deg[maxn + 5], n, m;
vector<int> ch[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    read(n); read(m);
    For(i, 1, m) {
        int u, v; read(u); read(v);
        ch[u].pb(v);
        deg[v]++;
    }
    priority_queue<int> q;
    For(i, 1, n) if(!deg[i]) q.push(i);
    while(q.size()) {
        int u = q.top(); q.pop();
        printf("%d ", u);
        for(auto v : ch[u]) {
            deg[v]--;
            if(!deg[v]) q.push(v);
        }
    }
}
