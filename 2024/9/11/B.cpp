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

#define maxn 5000
int T, n, a[maxn + 5];

void mian() {
    read(n);
    int tp = 0;
    LL res = 0;
    For(i, 1, n) {
        int x; read(x);
        int fl = 0;
        For(j, 1, tp) {
            if(a[j] > x) {
                res += j + tp - j + 1;
                fl = 1;
                Rof(p, tp, j) a[p + 1] = a[p];
                a[j] = x;
                break;
            }
        }
        // cout << fl << endl;
        if(!fl) a[++tp] = x, res += tp;
    }
    // printf("%lld\n", 1ll * n * (n + 1) / 2);
    // return;
    printf("%lld\n", res);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
