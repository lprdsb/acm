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
int n, a[maxn + 5], b[maxn + 5], cnt = 0;

int tr[maxn + 5];
void ins(int x, int y) {
    while(x <= maxn) tr[x] += y, x += x & -x;
}
int find(int x) {
    int now = 0;
    Rof(o, 19, 0) {
        int to = now | (1 << o);
        if(to <= maxn && tr[to] < x) {
            now = to;
            x -= tr[to];
        }
    }
    return b[now + 1];
}

int main() {
    //freopen("in", "r", stdin);
    read(n);
    For(i, 1, n) read(a[i]), b[++cnt] = a[i];
    sort(b + 1, b + cnt + 1);
    cnt = unique(b + 1, b + cnt + 1) - b - 1;
    For(i, 1, n) a[i] = lower_bound(b + 1, b + cnt + 1, a[i]) - b;
    For(i, 1, n) ins(a[i], 1);
    For(i, 1, n) {
        ins(a[i], -1);
        if(n & 1) printf("%.1lf\n", (DD)(find(n >> 1) + find((n >> 1) + 1)) / 2);
        else printf("%.1lf\n", (DD)find(n >> 1));
        ins(a[i], 1);
    }
    return 0;
}
