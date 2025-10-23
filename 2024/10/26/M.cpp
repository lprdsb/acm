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
int T, n, st[2][maxn + 5], tp[2];

void mian() {
    read(n);
    tp[0] = tp[1] = 0;
    For(i, 2, n) {
        if(i * i > n) break;
        if(n % i == 0) {
            st[0][++tp[0]] = i;
            if(i * i != n) st[1][++tp[1]] = n / i;
        }
    }
    Rof(i, tp[1], 1) st[0][++tp[0]] = st[1][i];
    st[0][++tp[0]] = n;
    st[0][++tp[0]] = n + 1;
    LL res = 0;
    res += 1ll * n * (st[0][1] - 1);
    For(i, 2, tp[0]) res += 1ll * (st[0][i] - st[0][i - 1]) * (n / st[0][i - 1]);
    cout << res << endl;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
