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

#define maxn 300000
int T, n, dif[2][maxn + 5], to[2][maxn + 5];
LL a[maxn + 5], s[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        read(n);
        For(i, 1, n) read(a[i]), s[i] = s[i - 1] + a[i];
        dif[0][0] = dif[0][1] = to[0][1] = 0; dif[1][n + 1] = dif[1][n] = to[1][n] = n + 1;
        For(i, 2, n) {
            if(a[i] == a[i - 1]) dif[0][i] = dif[0][i - 1];
            else dif[0][i] = i - 1;
            int l = 1, r = i;
            while(l < r) {
                int md = l + r >> 1;
                if(s[i - 1] - s[md - 1] <= a[i]) r = md;
                else l = md + 1;
            }
            to[0][i] = l - 1;
        }
        Rof(i, n - 1, 1) {
            if(a[i] == a[i + 1]) dif[1][i] = dif[1][i + 1];
            else dif[1][i] = i + 1;
            int l = i, r = n + 1;
            while(l < r) {
                int md = l + r >> 1;
                if(s[md] - s[i] > a[i]) r = md;
                else l = md + 1;
            }
            to[1][i] = l;
        }
        For(i, 1, n) {
            // if((dif[0][i] == 0 || to[0][i]) && (dif[1][i] == n + 1 || to[1][i] == n + 1)) printf("-1");
            int res = inf;
            if(i != 1 && a[i - 1] > a[i]) res = 1;
            if(i != n && a[i + 1] > a[i]) res = 1;
            if(dif[0][i - 1] != 0 && to[0][i] != 0) res = min(res, max(i - dif[0][i - 1], i - to[0][i]));
            if(dif[1][i + 1] != n + 1 && to[1][i] != n + 1) res = min(res, max(dif[1][i + 1] - i, to[1][i] - i));
            printf("%d ", res == inf ? -1 : res);
        }
        puts("");
    }
}
