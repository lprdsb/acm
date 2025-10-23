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

#define maxn 1000000
int n, k, l, r, a[maxn + 5];
#define mod 1000000007

int main() {
    //freopen("in", "r", stdin);
    read(n); read(k); read(l); read(r);
    int res = 0, now = 0;
    a[0]++; a[1]--;
    For(i, 0, n) {
        now = (now + a[i]) % mod;
        res = (res + now) % mod;
        if(i + l <= n) {
            a[i + l] = (a[i + l] + 1ll * now * k % mod) % mod;
            if(i + r + 1 <= n) a[i + r + 1] = (a[i + r + 1] - 1ll * now * k % mod + mod) % mod;
        }
    }
    cout << res << endl;
}
