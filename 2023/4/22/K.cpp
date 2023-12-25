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
#define maxn 500000
#define mod 998244353
using namespace std;

int t, n, bas = 1331, hsh[2][maxn + 5], fac[maxn + 5];
char s[maxn + 5];

template <class T>
void read(T & x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

bool chk1(int l, int r) {
    int v1 = (hsh[0][l] - 1ll * fac[r - l + 1] * hsh[0][r + 1] % mod + mod) % mod;
    int v2 = (hsh[1][r] - 1ll * fac[r - l + 1] * hsh[1][l - 1] % mod + mod) % mod;
    return v1 == v2;
}

bool chk2(int l1, int r1, int l2, int r2) {
    int v1 = (hsh[0][l1] - 1ll * fac[r1 - l1 + 1] * hsh[0][r1 + 1] % mod + mod) % mod;
    int v2 = (hsh[0][l2] - 1ll * fac[r2 - l2 + 1] * hsh[0][r2 + 1] % mod + mod) % mod;
    return v1 == v2;
}


int main() {
    // freopen("in.txt", "r", stdin);
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * bas % mod;
    read(t);
    while(t--) {
        scanf("%s", s + 1); n = strlen(s + 1);
        hsh[0][n + 1] = hsh[1][0] = 0;
        Rof(i, n, 1)
            hsh[0][i] = (1ll * bas * hsh[0][i + 1] % mod + s[i] - 'a' + 1) % mod;
        For(i, 1, n)
            hsh[1][i] = (1ll * bas * hsh[1][i - 1] % mod + s[i] - 'a' + 1) % mod;
        int now = 1;
        while(now <= n - now && s[now] == s[n - now + 1]) now++;
        if(now > n - now) puts("Yes");
        else {
            int fl = 0;
            if(n & 1) {
                int mid = (1 + n) >> 1;
                For(i, 0, n) {
                    if(s[mid - i] != s[mid + i]) break;
                    if(chk2(now, mid - i - 1, mid + i + 1, n - now + 1)) {
                        fl = 1;
                        break;
                    }
                }
            }
            else {
                int mid = n >> 1;
                if(chk2(now, mid, mid + 1, n - now + 1)) fl = 1;
                if(!fl){
                    For(i, 0, n) {
                        if(s[mid - i] != s[mid + 1 + i]) break;
                        if(chk2(now, mid - i - 1, mid + 1 + i + 1, n - now + 1)) {
                            fl = 1;
                            break;
                        }
                    }
                }
            }
            if(fl) puts("Yes");
            else {
                For(i, now, n - now + 1) if(chk1(now, i) && !((n - now + 1 - i) & 1)) {
                    int len = n - now + 1 - i;
                    len >>= 1;
                    if(chk2(i + 1, i + len, i + len + 1, n - now + 1)) {
                        fl = 1;
                        break;
                    }
                }
                Rof(i, n - now + 1, now) if(chk1(i, n - now + 1) && !((i - now) & 1)) {
                    int len = i - now;
                    len >>= 1;
                    if(chk2(now, now + len - 1, now + len, i - 1)) {
                        fl = 1;
                        break;
                    }
                }
                puts(fl ? "Yes" : "No");
            }
        }
    }
    return 0;
}