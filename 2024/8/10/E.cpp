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

#define maxn 500000
int n, k, a[maxn + 5], b[maxn + 5];

int q[2][maxn + 5], l[2] = { 1, 1 }, r[2] = { 0, 0 }, lpr[2] = { 0, 0 }, g[maxn + 5];
int f[maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    memset(f, inf, sizeof f);
    read(n); read(k);
    For(i, 1, n) {
        char c; cin >> c;
        a[i] = c == 'B';
    }
    For(i, 1, n) {
        char c; cin >> c;
        b[i] = c == 'B';
    }
    f[0] = 0; g[0] = 1;
    q[b[1]][++r[b[1]]] = 0;
    For(i, 1, n) {
        if(a[i] == b[i]) f[i] = min(f[i], f[i - 1]);
        For(o, 0, 1) if(l[o] <= r[o]) f[i] = min(f[i], f[q[o][l[o]]] + g[q[o][l[o]]] + lpr[o]);
        if(b[i + 1] != b[i]) lpr[!b[i + 1]]++;
        while(l[b[i + 1]] <= r[b[i + 1]] && f[q[b[i + 1]][r[b[i + 1]]]] + lpr[b[i + 1]] + g[q[b[i + 1]][r[b[i + 1]]]] >= f[i] + 1) r[b[i + 1]]--;
        q[b[i + 1]][++r[b[i + 1]]] = i;
        g[i] -= lpr[b[i + 1]] - 1;
        For(o, 0, 1) {
            while(l[o] <= r[o] && q[o][l[o]] <= i - k) l[o]++;
        }
    }
    printf("%d\n", f[n]);
    return 0;
}
