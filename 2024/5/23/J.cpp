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

int T, a[200][5], vis[5], tot = 0;

int b[5];
void dfs(int pos) {
    if(pos == 5) {
        tot++;
        For(i, 0, 4) a[tot][i] = b[i];
        return;
    }
    For(i, 0, 4) if(!vis[i]) {
        b[pos] = i;
        vis[i] = 1;
        dfs(pos + 1);
        vis[i] = 0;
    }
}

#define maxn 100000
int pri[maxn + 5], cnt = 0, pvis[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    For(i, 2, maxn) {
        if(!pvis[i]) pri[++cnt] = i;
        for(int j = 1; j <= cnt && i * pri[j] <= maxn; ++j) {
            pvis[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
        }
    }
    dfs(0);
    // cout << pvis[] << endl;
    read(T);
    while(T--) {
        For(i, 0, 4) {
            char c; cin >> c;
            b[i] = c - '0';
        }
        int fl = 0;
        For(i, 1, tot) {
            int now = 0;
            For(j, 0, 4) now = now * 10 + b[a[i][j]];
            if(now >= 10000 && pvis[now]) {
                printf("%d\n", now);
                fl = 1;
                break;
            }
        }
        if(!fl) puts("-1");
    }
}
