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

int T, n;
LL a, b, s;
#define maxn 200000
int f[maxn + 5], g[maxn + 5], h[705];
void mian() {
    read(n); read(a); read(b); read(s);
    s -= a % b * n;
    if(s < 0 || s % b) {
        puts("No");
        return;
    }
    s /= b;
    For(i, 1, n) {
        LL tem = a / b + i - 1, tem1 = 1ll * (a / b + tem) * i / 2;
        // if(i == 2) cout << f[1] << endl;
        if(tem1 <= s && i + f[s - tem1] <= n) {
            puts("Yes");
            // cout << f[4] << endl;
            For(j, 1, i) printf("%d ", a + (j - 1) * b);
            int now = s - tem1;
            while(now) {
                For(j, 1, g[now]) printf("%d ", a % b + (j - 1) * b);
                now -= h[g[now]];
            }
            For(j, i + f[s - tem1] + 1, n) printf("%d ", a % b);
            puts("");
            return;
        }
    }
    puts("No");
}

int main() {
    // freopen("in.txt", "r", stdin);
    For(i, 1, 700) h[i] = h[i - 1] + i - 1;
    memset(f, inf, sizeof f);
    f[0] = 0;
    For(i, 0, maxn) For(j, 1, 700) if(i + h[j] <= maxn && f[i] + j < f[i + h[j]]) {
        f[i + h[j]] = f[i] + j;
        g[i + h[j]] = j;
    }
    read(T);
    while(T--) {
        mian();
    }
}
