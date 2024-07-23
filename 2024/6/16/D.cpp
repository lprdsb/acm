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
int T, n, num[maxn + 5], f[maxn + 5];

void mian() {
    read(n);
    For(i, 0, n) num[i] = 0;
    For(i, 1, n) {
        int x; read(x);
        if(x < n + 10) num[x]++;
    }
    int mex = inf;
    For(i, 0, n) if(!num[i]) {
        mex = i;
        break;
    }
    For(i, 0, n) f[i] = inf;
    f[mex] = 0;
    Rof(i, mex, 0) if(f[i] != inf) {
        For(j, 0, i - 1) f[j] = min(f[j], f[i] + num[j] * i);
    }
    printf("%d\n", f[0] - mex);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
