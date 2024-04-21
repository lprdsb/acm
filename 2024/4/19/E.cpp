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
int n, a[maxn + 5][maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    read(n); int t; read(t);
    For(i, 0, n - 1) a[i][i] = 1;
    For(o, 1, t) {
        For(i, 1, n - 1) {
            For(j, 0, n - 1) a[i][j] -= a[i - 1][j];
        }
        For(j, 0, n - 1) a[0][j] -= a[n - 1][j];
    }
    For(i, 0, n - 1) {
        For(j, 0, n - 1) printf("%d ", a[i][j]); puts("");
    }
}
