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

#define P 1000003

int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % P;
        x = 1ll * x * x % P;
        y >>= 1;
    }
    return res;
}

#define maxn 500000
int a[2][maxn + 5], res = 1;

int main() {
    //freopen("in", "r", stdin);
    int n, m;
    read(n); read(m);
    memset(a, -1, sizeof a);
    For(i, 1, n) For(j, 1, m) {
        char c; cin >> c;
        if(c != '.') {
            int f1 = 0, f2 = 0;
            f1 = (c == '1' || c == '2') ^ ((j + 1) & 1);
            f2 = (c == '1' || c == '4') ^ ((i + 1) & 1);
            if(a[0][i] != -1 && a[0][i] != f1) res = 0;
            if(a[1][j] != -1 && a[1][j] != f2) res = 0;
            a[0][i] = f1;
            a[1][j] = f2;
        }
    }
    For(i, 1, n) if(a[0][i] == -1) res = 2ll * res % P;
    For(i, 1, m) if(a[1][i] == -1) res = 2ll * res % P;
    printf("%d\n", res);
}
