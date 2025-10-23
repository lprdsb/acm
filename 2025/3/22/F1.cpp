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

#define maxn 400000
int T, n, k, a[maxn + 5], num[maxn + 5];

LL b[2][maxn + 5], c[2][maxn + 5];
void insb(int p, int x) {
    int t = x > 0 ? 1 : -1;
    b[0][p] += t;
    b[1][p] += x;
}
void insc(int p, int x) {
    int t = x > 0 ? 1 : -1;
    c[0][p] += t;
    c[1][p] += x;
}
LL get_s(int x) { return 1ll * x * (x - 1) / 2; }

void mian() {
    read(n); read(k);
    For(i, 1, n) read(a[i]);
    Rof(i, n, 1) {
        int md = min(n, i + num[a[i]] >> 1);
        insb(i, i);
        insb(md + 1, -i);
        if(num[a[i]] <= n) {
            insc(md, num[a[i]]);
            insc(num[a[i]], -num[a[i]]);
        }
        num[a[i]] = i;
    }
    For(i, 1, k) {
        insc(0, num[i]);
        insc(num[i], -num[i]);
    }
    For(i, 1, n) {
        For(o, 0, 1) {
            b[o][i] += b[o][i - 1];
            c[o][i] += c[o][i - 1];
        }
    }
    // cout << b[1][1] << endl;
    LL res = Inf;
    For(i, 0, n - 1) {
        LL tmp = 1ll * i * b[0][i] - b[1][i] + c[1][i] - 1ll * (i + 1) * c[0][i];
        res = min(res, tmp);
        // cout << i << " " << tmp << endl;
    }
    res -= get_s(k / 2) + get_s(k - k / 2);
    cout << res << endl;
}

int main() {
    // freopen("in.txt", "r", stdin);
    memset(num, inf, sizeof num);
    read(T);
    while(T--) {
        mian();
        For(i, 0, n + 1) {
            For(o, 0, 1) b[o][i] = c[o][i] = 0;
            num[i] = inf;
        }
    }
}

