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

#define maxn 200000
int mod[2] = { 998244353, 1000000007 };
int T, n, q, a[maxn + 5], hsh[maxn + 5][2], bas = 13331, pw[maxn + 5][2], hhsh[maxn + 5][2];
bool cmp(int l1, int r1, int l2, int r2) {
    For(o, 0, 1)
        if((hsh[r1][o] - 1ll * hsh[l1 - 1][o] * pw[r1 - l1 + 1][o] % mod[o] + mod[o]) % mod[o]
            != (hsh[r2][o] - 1ll * hsh[l2 - 1][o] * pw[r2 - l2 + 1][o] % mod[o] + mod[o]) % mod[o]) {
            return 0;
        }
    return 1;
}
bool chk(int l, int r) {
    For(o, 0, 1) if((hsh[r][o] - 1ll * hsh[l - 1][o] * pw[r - l + 1][o] % mod[o] + mod[o]) % mod[o]
        != (hhsh[l][o] - 1ll * hhsh[r + 1][o] * pw[r - l + 1][o] % mod[o] + mod[o]) % mod[o])
        return 0;
    return 1;
}
void mian() {
    read(n); read(q);
    pw[0][0] = pw[0][1] = 1;
    For(i, 1, n) For(o, 0, 1) pw[i][o] = 1ll * pw[i - 1][o] * bas % mod[o];
    For(i, 1, n) {
        char c; cin >> c;
        a[i] = c - 'a' + 1;
        For(o, 0, 1) {
            hsh[i][o] = (1ll * hsh[i - 1][o] * bas % mod[o] + a[i]) % mod[o];
        }
    }
    // cout << cmp(1, 4, 3, 6) << endl;
    hhsh[n + 1][0] = hhsh[n + 1][1] = 0;
    Rof(i, n, 1) {
        For(o, 0, 1) {
            hhsh[i][o] = (1ll * hhsh[i + 1][o] * bas % mod[o] + a[i]) % mod[o];
        }
    }
    while(q--) {
        int l, r; read(l); read(r);
        if(cmp(l, r - 1, l + 1, r)) puts("0");
        else if(r - l == 1) puts("2");
        else if(cmp(l, r - 2, l + 2, r)) {
            int ll = 2, rr = r - l + 1;
            if(rr & 1) rr--;
            // cout << ll << " " << rr << endl;
            printf("%lld\n", 1ll * (ll + rr) * ((rr - ll) / 2 + 1) / 2);
        }
        else {
            if(!chk(l, r)) printf("%lld\n", 1ll * (r - l + 1) * (r - l + 2) / 2 - 1);
            else printf("%lld\n", 1ll * (r - l + 1) * (r - l + 2) / 2 - 1 - (r - l + 1));
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
