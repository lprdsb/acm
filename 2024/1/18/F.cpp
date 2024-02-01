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

#define maxn 100
int T, n, k, a[maxn + 5], f[maxn + 5][maxn + 5], g[maxn + 5][maxn + 5], cnt[maxn + 5];

int L[maxn + 5], R[maxn + 5];
void mian() {
    read(n); read(k);
    For(i, 1, n) read(a[i]); a[n + 1] = 0;
    if(n == 1) {
        puts("0");
        return;
    }
    Rof(l, n, 1) For(r, l, n) if(a[l] == a[r]) {
        vector<int> vec;
        For(i, 1, k) L[i] = R[i] = 0;
        For(i, l, r) {
            if(!L[a[i]]) L[a[i]] = i;
            R[a[i]] = i;
            cnt[a[i]]++;
            if(a[i] == a[l]) vec.pb(i);
        }
        For(i, 1, k) {
            if(!cnt[i]) g[l][r] = 1;
            cnt[i] = 0;
            g[l][r] = min(g[l][r], g[L[i]][R[i]] + 1);
        }
        for(int i = 0; i <= (int)vec.size() - 2; ++i) g[l][r] = min(g[l][r], g[l][vec[i]] + g[vec[i + 1]][r]);
    }
    For(i, 0, n) f[i + 1][i] = 0;
    Rof(l, n, 1) For(r, l, n) if(a[l - 1] == a[r + 1] || l == 1 || r == n) {
        if(l == r) {
            if(l != 1) f[l][r] = a[l] != a[l - 1];
            else if(r != n) f[l][r] = a[l] != a[r + 1];
        }
        else {
            For(i, 1, k) L[i] = R[i] = 0;
            For(i, l, r) {
                if(!L[a[i]]) L[a[i]] = i;
                R[a[i]] = i;
            }
            int o1 = 1, o2 = k, to = 0;
            if(l != 1) o1 = o2 = to = a[l - 1];
            if(r != n) o1 = o2 = to = a[r + 1];
            For(i, o1, o2) {
                if(!L[i]) f[l][r] = min(f[l][r], 1);
                else f[l][r] = min(f[l][r], g[L[i]][R[i]] + 1);
            }
            For(i, l, r) if(!to || a[i] == to) f[l][r] = min(f[l][r], f[l][i - 1] + f[i + 1][r]);
        }
    }
    printf("%d\n", f[1][n]);
}

int main() {
    // freopen("in.txt", "r", stdin);
    memset(f, inf, sizeof f);
    memset(g, inf, sizeof g);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) For(j, i, n) f[i][j] = g[i][j] = inf;
    }
}
