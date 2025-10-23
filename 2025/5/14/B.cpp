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

int tr[maxn + 5];
void ins(int x) {
    while(x <= n) tr[x]++, x += x & -x;
}
int que(int x) {
    int res = 0;
    while(x) res += tr[x], x -= x & -x;
    return res;
}

int idx[2][maxn + 5], tp[2], as[maxn + 5];
void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    tp[0] = tp[1] = 0;
    For(i, 1, n) idx[i & 1][++tp[i & 1]] = i;
    For(i, 1, n) tr[i] = 0;
    int tmp = 0;
    For(i, 1, n) {
        tmp ^= que(a[i]) & 1;
        ins(a[i]);
    }
    For(o, 0, 1) {
        sort(idx[o] + 1, idx[o] + tp[o] + 1, [](int x, int y) {return a[x] < a[y];});
    }
    For(i, 1, n) as[i] = a[idx[i & 1][(i + 1) >> 1]];

    For(i, 1, n) tr[i] = 0;
    For(i, 1, n) {
        tmp ^= que(as[i]) & 1;
        ins(as[i]);
    }
    if(tmp) swap(as[n], as[n - 2]);
    For(i, 1, n) printf("%d ", as[i]); puts("");
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
