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

#define maxn 300
#define maxm 60000
int n, q, m, k, B = 800, bas = 13331;
int a[maxn + 5][maxm + 5], b[maxm + 5];
int hsh[maxn + 5][1005], hh[1005];
#define mod 998244353

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(q); read(m); read(k);
    For(i, 1, n) For(j, 0, m - 1) {
        char c; cin >> c;
        a[i][j] = c - 'a' + 1;
        hsh[i][j / B] = (1ll * bas * hsh[i][j / B] + a[i][j]) % mod;
    }
    while(q--) {
        For(i, 0, B) hh[i] = 0;
        For(i, 0, m - 1) {
            char c; cin >> c;
            b[i] = c - 'a' + 1;
            hh[i / B] = (1ll * bas * hh[i / B] + b[i]) % mod;
        }
        int res = 0;
        For(i, 1, n) {
            int cnt = 0;
            For(j, 0, B - 1) if(hh[j] != hsh[i][j]) {
                For(p, j * B, (j + 1) * B - 1) {
                    cnt += a[i][p] != b[p];
                    if(cnt > k) break;
                }
                if(cnt > k) break;
            }
            res += cnt <= k;
        }
        printf("%d\n", res);
    }
}
