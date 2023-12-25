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

#define maxn 100000
int n;
LL a[maxn + 5], b[maxn + 5];

int tr[maxn + 5];
void ins(int x) {
    while(x <= maxn) tr[x]++, x += x & -x;
}
int que(int x) {
    int res = 0;
    while(x) res += tr[x], x -= x & -x;
    return res;
}

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int main() {
    //freopen("in", "r", stdin);
    read(n);
    int cnt = 0;
    For(i, 1, n) read(a[i]), a[i] += a[i - 1], b[++cnt] = a[i];
    // For(i, 1, n) cout << a[i] << " "; cout << endl;
    sort(b + 1, b + cnt + 1);
    if(b[1] < 0 || a[n] != b[cnt]) {
        puts("-1");
        return 0;
    }
    cnt = unique(b + 1, b + cnt + 1) - b - 1;
    LL res = 0;
    Rof(i, n, 1) {
        int tem = lower_bound(b + 1, b + cnt + 1, a[i]) - b;
        ins(tem);
        res += que(tem - 1);
    }
    printf("%lld\n", res);
    return 0;
}
