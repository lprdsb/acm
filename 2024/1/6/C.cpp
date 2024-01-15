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
int T, n, a[maxn + 5];
int tr[2][maxn + 5];

void ins(int o, int x, int y) {
    if(o) x = n - x + 1;
    while(x <= n) tr[o][x] = min(tr[o][x], y), x += x & -x;
}
int que(int o, int x) {
    if(o) x = n - x + 1;
    int res = inf;
    while(x) res = min(res, tr[o][x]), x -= x & -x;
    return res;
}

void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    if(n == 1) {
        puts("0");
        return;
    }
    int sum = 0;
    For(o, 0, 1) ins(o, n, 0);
    For(i, 2, n) {
        int tem = min(que(0, a[i] - 1) + 1, que(1, a[i])) + sum;
        sum += a[i] > a[i - 1];
        For(o, 0, 1) ins(o, a[i - 1], tem - sum);
        if(i == n) printf("%d\n", que(0, n) + sum);
    }
}

int main() {
    //freopen("in", "r", stdin);
    memset(tr, inf, sizeof tr);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) tr[0][i] = tr[1][i] = inf;
    }
}
