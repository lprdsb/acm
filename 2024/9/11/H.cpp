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
int tr[maxn + 5];
void ins(int x) {
    while(x <= maxn) tr[x] += 1, x += x & -x;
}
int que(int x) {
    int res = 0;
    while(x) res += tr[x], x -= x & -x;
    return res;
}

int n, k, a[maxn + 5], b[maxn + 5], cnt = 0;

int main() {
    //freopen("in", "r", stdin);
    read(n); read(k);
    For(i, 1, n) read(a[i]), b[++cnt] = a[i];
    sort(b + 1, b + cnt + 1);
    cnt = unique(b + 1, b + cnt + 1) - b - 1;
    b[++cnt] = inf;
    LL res = 0;
    Rof(i, n, 1) {
        int tem = lower_bound(b + 1, b + cnt + 1, a[i]) - b;
        int to = (a[i] - 1) / k + 1;
        res += que(lower_bound(b + 1, b + cnt + 1, to) - b - 1);
        ins(tem);
    }
    printf("%lld\n", res);
}
