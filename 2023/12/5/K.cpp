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
void read(T &x){
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define maxn 5000
int T;
int n, m, a[maxn + 5], b[maxn + 5], f[maxn + 5][maxn + 5], g[maxn + 5][maxn + 5];
void sol(){
    read(n); read(m);
    int s1 = 0, s2 = 0;
    For(i, 1, n){
        char c; cin >> c;
        if(c == 'Q') a[i] = 1;
        if(c == 'B') a[i] = 2;
        s1 += a[i] == 1;
        s2 += a[i] == 2;
    }
    n--;
    For(i, 1, m){
        char c; cin >> c;
        if(c == 'Q') b[i] = 1;
        if(c == 'B') b[i] = 2;
    }
    g[0][s2] = 1;
    For(i, 0, m){
        s1 += b[i] == 1;
        s2 += b[i] == 2;
        For(j, 0, s2) if(g[i][j]){
            int u1 = i - 2 * (s2 - j), r1 = s1 - u1;
            if(r1) g[i + 1][j + (b[i + 1] == 2)] = 1;
            if(j) g[i + 2][j - 1 + (b[i + 1] == 2) + (b[i + 2] == 2)] = 1;
        }
    }
    For(i, 0, s2) f[m][i] = f[m + 1][i] = f[m + 2][i] = 0;
    int res = inf;
    Rof(i, m, 0){
        For(j, 0, s2){
            int c[2] = {b[i + 1] == 1, b[i + 1] == 2};
            if(j) f[i][j] = min(f[i][j], max(0, f[i + 2][j - 1 + c[1]] - c[0]));
            f[i][j] = min(f[i][j], max(1, f[i + 1][j + c[1]] - c[0] + 1));
        }
        For(j, 0, s2) if(g[i][j]){
            int u1 = i - (s2 - j) * 2, r1 = s1 - u1;
            if(r1 >= f[i][j]) res = min(res, n + i - (s2 - j) - u1);
        }
        s1 -= b[i] == 1;
        s2 -= b[i] == 2;
    }
    if(res == inf) puts("IMPOSSIBLE");
    else printf("%d\n", res + 1);
    // n++;
}

int main(){
    // freopen("in.txt", "r", stdin);
    memset(f, inf, sizeof f);
    read(T);
    while(T--){
        sol();
        For(i, 1, n + 1) a[i] = 0;
        For(i, 1, m) b[i] = 0; 
        For(i, 0, m + 2){
            For(j, 0, n + m + 1){
                f[i][j] = inf;
                g[i][j] = 0;
            }
        }
    }
}
