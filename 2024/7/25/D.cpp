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

#define maxn 2048
int s, n, p[2], q[2];
LL f[2][maxn + 5];

LL get_mx(int n) {
    LL res = 0;
    For(o, 0, 1) {
        int tem = n + 1 - (DD)p[o] / q[o];
        int lim = min(n, max(0, tem));
        // cout << tem << endl;
        LL mx = 0;
        For(k, max(0, lim - 1), min(n, lim + 1)) {
            // cout << k << " " << 1ll * k * (1ll * n * (q[0] + q[1]) - p[0] - p[1]) - 1ll * (q[0] + q[1]) * k * (k - 1) / 2 << endl;
            mx = max(mx, 1ll * k * (1ll * n * q[o] - p[o]) - 1ll * q[o] * k * (k - 1) / 2);
        }
        res += mx;
    }
    return res;
}

int main() {
    memset(f, -1, sizeof f);
    // freopen("in.txt", "r", stdin);
    read(s); read(n);
    For(o, 0, 1) read(p[o]), read(q[o]);
    int up = p[0] + p[1];
    int o = 0; f[o][0] = s;
    LL res = 0;
    For(i, 0, min(n, 30000)) {
        int tot = 0;
        For(j, 0, up - 1) if(f[o][j] != -1) {
            For(o1, 0, 1)  if(f[o][j] >= p[o1]) {
                if(j + q[o1] >= up) res = max(res, f[o][j] - p[o1] + 1ll * (j + q[o1]) * (n - i) + get_mx(n - i - 1));
                else f[o ^ 1][j + q[o1]] = max(f[o ^ 1][j + q[o1]], f[o][j] - p[o1] + j + q[o1]);
            }
            if(f[o][j] >= p[0] + p[1]) {
                if(j + q[0] + q[1] >= up) res = max(res, f[o][j] - p[0] - p[1] + 1ll * (j + q[0] + q[1]) * (n - i) + get_mx(n - i - 1));
                else f[o ^ 1][j + q[0] + q[1]] = max(f[o ^ 1][j + q[0] + q[1]], f[o][j] - p[0] - p[1] + j + q[0] + q[1]);
            }
            f[o ^ 1][j] = max(f[o ^ 1][j], f[o][j] + j);
            res = max(res, f[o][j] + 1ll * j * (n - i));
            f[o][j] = -1;
        }
        o ^= 1;
    }
    printf("%lld\n", res);
}
