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
int T, n, k, a[maxn + 5], b[maxn + 5];

int tr[maxn + 5], up;
void ins(int x) {
    while(x <= up) tr[x]++, x += x & -x;
}
int que(int x) {
    int res = 0;
    while(x) res += tr[x], x -= x & -x;
    return res;
}


#define mod 998244353
void sol() {
    read(n); read(k); up = max(2 * n, k);
    For(i, 1, n) read(a[i]);
    For(i, 1, k) read(b[i]), b[i]++;
    int res = 0;
    Rof(i, k, 1) {
        res = (res + que(b[i])) % mod;
        ins(b[i]);
    }
    res = 1ll * res * n % mod;
    For(i, 1, up) tr[i] = 0;
    Rof(i, n, 1) {
        int tem = a[i], l = 0;
        while(tem && l < k) {
            res = (res + 1ll * (k - l) * que(tem) % mod) % mod;
            tem >>= 1;
            l++;
        }
        tem = 2 * a[i]; l = 1;
        while(l < k && tem < 2 * n) {
            res = (res + 1ll * (k - l) * que(tem) % mod) % mod;
            tem <<= 1;
            l++;
        }
        if(tem >= 2 * n) res = (res + 1ll * (k - l) * (k - l + 1) / 2 * (n - i) % mod) % mod;
        ins(a[i]);
    }
    printf("%d\n", res);
    For(i, 1, up) tr[i] = 0;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        sol();
    }
}
