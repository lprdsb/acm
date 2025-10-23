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
int T, n, x, a[maxn + 5], b[maxn + 5], q[maxn + 5];

void mian() {
    read(n); read(x);
    For(i, 0, n - 1) read(a[i]);
    For(i, 0, n - 1) b[i] = 0;
    b[a[0]] = 1;
    int l = 1, r = 0;
    q[++r] = a[0];
    while(l <= r) {
        int u = q[l++];
        // cout << u << " " << b[u] << endl;
        int to = u + 1;
        if(to == n) to = 0;
        if(!b[to]) {
            b[to] = b[u] + 1;
            q[++r] = to;
        }
        to = (u + a[u]);
        if(to >= n) to -= n;
        if(!b[to]) {
            b[to] = b[u] + 1;
            q[++r] = to;
        }
        assert(r <= n);
    }
    printf("%d\n", b[x]);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
