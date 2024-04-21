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
#define eps 1e-8
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
int n, q;
LL a[maxn + 5], b[maxn + 5];

LL sqrt(LL x) {
    LL res = 0;
    Rof(o, 30, 0) {
        LL to = res | (1ll << o);
        if(to * to <= x) res = to;
    }
    return res;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(q);
    For(i, 1, n) a[i] = 1e17, b[i] = sqrt(b[i - 1] + a[i]);
    // printf("%lld\n", b[2]);
    For(_, 1, q) {
        int k = _; LL x = 1;// read(k); read(x);
        a[k] = x;
        int now = k;
        LL pre = b[now - 1];
        int tot = 0;
        while(now <= n) {
            tot++;
            LL tem = sqrt(pre + a[now]) + eps;
            if(tem == b[now]) break;
            b[now] = tem;
            pre = b[now];
            now++;
        }
        cout << tot << endl;
        // printf("%lld\n", b[n]);
    }
}
