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

#define maxn 16
#define maxm 2000
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int n;
int poi[17][2];
int R[20];
int ma[2 * maxm + 5][2 * maxm + 5];

int mx = 0;
void dfs(int dep, int sum) {
    if(dep == n / 2 + 1) {
        mx = max(mx, sum);
        return;
    }
    int tem = R[0];
    R[0] = R[R[0]];
    int now = R[0], pre = 0;
    while(now != n + 1) {
        R[pre] = R[now];
        int dx = poi[now][0] - poi[tem][0], dy = poi[now][1] - poi[tem][1], gc = gcd(dx, dy);
        dx /= gc; dy /= gc;
        if(dx < 0) dx = -dx, dy = -dy;
        int ds = ma[dx + maxm][dy + maxm]; ma[dx + maxm][dy + maxm]++;
        dfs(dep + 1, sum + ds);
        ma[dx + maxm][dy + maxm]--;
        R[pre] = now;
        pre = now;
        now = R[now];
    }
    R[0] = tem;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n);
    For(i, 1, n) read(poi[i][0]), read(poi[i][1]);
    For(i, 0, n) R[i] = i + 1;
    dfs(1, 0);
    printf("%d\n", mx);
}
