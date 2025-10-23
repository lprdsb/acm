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
int T, n, m, L[maxn + 5], R[maxn + 5], as[maxn + 5], vis[maxn + 5];
vector<int> ch[maxn + 5];

void mian() {
    read(n); read(m);
    For(i, 1, m) {
        int u, v; read(u); read(v);
        ch[u].pb(v);
        ch[v].pb(u);
    }
    For(i, 1, n) sort(ch[i].begin(), ch[i].end());
    For(i, 0, n) R[i] = i + 1;
    For(i, 1, n + 1) L[i] = i - 1;
    For(i, 1, n) if(!vis[i]) {
        queue<int> q;
        q.push(i);
        L[R[i]] = L[i];
        R[L[i]] = R[i];
        while(q.size()) {
            int u = q.front(); q.pop();
            vis[u] = i;
            as[i]++;
            int now = R[0];
            for(auto v : ch[u]) {
                // if(u == 2) cout << v << endl;
                while(now < v) {
                    // cout << "asd" << endl;
                    q.push(now);
                    L[R[now]] = L[now];
                    R[L[now]] = R[now];
                    now = R[now];
                }
                if(now == v) now = R[now];
            }
            while(now <= n) {
                q.push(now);
                L[R[now]] = L[now];
                R[L[now]] = R[now];
                now = R[now];
            }
        }
    }
    For(i, 1, n) printf("%d ", as[vis[i]]);
    puts("");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) {
            ch[i].resize(0);
            as[i] = 0;
            vis[i] = 0;
        }
    }
}
