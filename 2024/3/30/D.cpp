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
int T, n, k;
int a[maxn + 5][maxn + 5];
LL f[maxn + 5][5 * maxn + 5];
struct Node {
    LL val;
    int pos, k;
};
bool operator < (cst Node &x, cst Node &y) { return x.val < y.val; }
void mian() {
    read(n); read(k);
    For(i, 1, n) For(j, i, n) read(a[i][j]);
    f[n + 1][1] = f[n + 2][1] = 0;
    Rof(i, n, 1) {
        priority_queue<Node> q;
        For(j, i - 1, n) q.push({ f[j + 2][1] + a[i][j], j, 1 });
        For(j, 1, k) {
            Node now = q.top(); q.pop();
            f[i][j] = now.val;
            q.push({ f[now.pos + 2][now.k + 1] + a[i][now.pos], now.pos, now.k + 1 });
        }
    }
    For(i, 1, k) printf("%lld ", f[1][i]); puts("");
}

int main() {
    // freopen("in.txt", "r", stdin);
    memset(f, -inf, sizeof f);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n + 2) For(j, 0, k) f[i][j] = -Inf;
    }
}