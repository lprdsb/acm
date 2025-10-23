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

int a[805][805], len;
void dfs(int n) {
    if(n == 1) {
        len = 1;
        a[1][1] = 1;
        return;
    }
    dfs(n - 1);
    For(i, 1, len) For(j, 1, len) a[i][len + j] = a[i][j];
    For(i, 1, len) For(j, 1, len) a[i][2 * len + j] = a[i][j];
    For(i, 1, len) For(j, 1, len) a[len + i][j] = a[i][j];
    For(i, 1, len) For(j, 1, len) a[len + i][2 * len + j] = a[i][j];
    For(i, 1, len) For(j, 1, len) a[2 * len + i][j] = a[i][j];
    For(i, 1, len) For(j, 1, len) a[2 * len + i][len + j] = a[i][j];
    For(i, 1, len) For(j, 1, len) a[2 * len + i][2 * len + j] = a[i][j];
    len *= 3;
    return;
}

int main() {
    //freopen("in", "r", stdin);
    int n; read(n); n++;
    dfs(n);
    For(i, 1, len) {
        For(j, 1, len) {
            if(a[i][j]) putchar('#');
            else putchar('.');
        }
        puts("");
    }
}
