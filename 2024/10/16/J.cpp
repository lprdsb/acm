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
int T, n, a[maxn + 5], f[maxn + 5][maxn + 5][maxn + 5], to[maxn + 5], pos[maxn + 5];

void mian() {
    read(n);
    For(i, 1, n) For(j, i, n) For(o, 0, n) f[i][j][o] = inf;
    For(i, 1, n) read(a[i]);
    For(i, 1, n) pos[i] = 0;
    For(i, 1, n) pos[i] = n + 1;
    Rof(i, n, 1) {
        to[i] = pos[a[i]];
        pos[a[i]] = i;
    }
    // For(i, 1, n) cout << to[i][1] << " "; cout << endl;
    For(len, 1, n) {
        For(l, 1, n - len + 1) {
            int r = l + len - 1;
            For(o, 0, n) {
                f[l][r][o] = r - l + 1;
                int now = l;
                while(now <= r) {
                    f[l][r][o] = min(f[l][r][o], f[l][now - 1][a[l]] + f[now + 1][r][o] + !(a[l] == o));
                    now = to[now];
                }
            }
        }
    }
    // cout << f[1][3][1] << endl;
    printf("%d\n", f[1][n][0]);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
