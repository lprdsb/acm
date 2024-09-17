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

#define maxn 300000
int T, n, a[maxn + 5], b[maxn + 5], p[maxn + 5];
LL len[maxn + 5];

LL tr[maxn + 5];
void ins(int x, LL y) {
    x = n - x + 1;
    while(x <= n) tr[x] = max(tr[x], y), x += x & -x;
}
LL que(int x) {
    x = n - x + 1;
    LL res = 0;
    while(x) res = max(res, tr[x]), x -= x & -x;
    return res;
}

int res = 0;
void mian() {
    read(n);
    For(i, 1, n) read(a[i]), read(b[i]);
    For(i, 1, n) {
        if(!p[b[i]]) ins(i, a[i]), p[b[i]] = i, len[b[i]] = a[i];
        else {
            LL tem = que(p[b[i]] + 1);
            if(a[i] >= tem) {
                len[b[i]] = a[i] + max(0ll, len[b[i]] - tem);
                ins(i, len[b[i]]);
                p[b[i]] = i;
            }
        }
        printf("%lld ", que(1));
    }
    puts("");
}

int main() {
    freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 0, n) b[i] = len[i] = tr[i] = 0;
    }
}
