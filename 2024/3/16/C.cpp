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

#define maxn 2000000
int n, q, ch[maxn + 5][2], tot = 0, a[maxn + 5];
LL sum[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    read(n); read(q);
    For(i, 0, n - 1) {
        read(a[i]);
        int now = 0;
        Rof(o, 19, 0) {
            int to = (i >> o) & 1;
            if(!ch[now][to]) ch[now][to] = ++tot;
            now = ch[now][to];
            sum[now] += a[i];
        }
    }
    while(q--) {
        int op, x, y; read(op); read(x); read(y);
        if(op == 1) {
            int now = 0;
            Rof(o, 19, 0) {
                int to = (x >> o) & 1;
                now = ch[now][to];
                sum[now] += y - a[x];
            }
            a[x] = y;
        }
        else {
            LL res = 0;
            int now = 0;
            Rof(o, 19, 0) {
                int to = ((y >> o) & 1), tto = to ^ ((x >> o) & 1);
                if(to) res += sum[ch[now][!tto]];
                now = ch[now][tto];
                if(!now) break;
            }
            printf("%lld\n", res + sum[now]);
        }
    }
}
