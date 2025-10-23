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

#define P 1000000007
#define maxn 10000000
int n, a[maxn + 5], st[maxn + 5], num[maxn + 5], pw[maxn + 5];

int chk(int x, int y) {
    if(num[x] >= 30) return 1;
    return 1ll * a[x] * (1ll << num[x]) >= a[y];
}

void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    int tp = 0;
    int res = 0;
    For(i, 1, n) {
        num[i] = 0;
        while(a[i] % 2 == 0) num[i]++, a[i] >>= 1;
        while(tp && chk(i, st[tp])) {
            // res = (res + a[st[tp]]) % P;
            num[i] += num[st[tp]];
            res = (res - 1ll * a[st[tp]] * pw[num[st[tp]]] % P + P) % P;
            res = (res + a[st[tp]]) % P;
            tp--;
        }
        st[++tp] = i;
        res = (res + 1ll * pw[num[i]] * a[i] % P) % P;
        printf("%d ", res);
    }
    puts("");
}

int main() {
    // freopen("in.txt", "r", stdin);
    pw[0] = 1;
    For(i, 1, maxn) pw[i] = 2ll * pw[i - 1] % P;
    int T; read(T);
    while(T--) {
        mian();
    }
}
