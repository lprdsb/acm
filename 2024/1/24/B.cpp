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

LL que(int l, int r) {
    printf("? %d %d\n", l, r);
    fflush(stdout);
    LL res; read(res);
    if(res == -1) exit(0);
    return res;
}

int T, n;
void mian() {
    read(n);
    LL sum = que(1, n);
    int l = 1, r = n, L, M, R;
    while(l < r) {
        int md = l + r >> 1;
        if(que(1, md)) r = md;
        else l = md + 1;
    }
    L = l - 1;
    M = sum - que(L + 1, n) + L + 1;
    if(M == n) R = n;
    else R = M + que(M, n) - que(M + 1, n);
    printf("! %d %d %d\n", L, M, R);
    fflush(stdout);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
