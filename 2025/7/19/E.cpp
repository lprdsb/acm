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

#define P 998244353


#define maxn 500
int T, n, k, f[maxn + 5][maxn + 5], a[maxn + 5], b[maxn + 5], c[maxn + 5];

void mian() {
    int bas = 1;
    read(n); read(k);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) read(b[i]);
    if(a[1] == -1) bas = k;
    if(b[n] == -1) bas = 1ll * bas * k % P;
    For(i, 1, n - 1) a[i] = a[i + 1];
    n--;
    For(i, 0, n) For(j, 0, k) f[i][j] = 0;
    // if(a[1] != -1 && b[1] != -1 && a[1] <= b[1]) f[0][0] = 1;
    // else f[0][k] = 1;
    f[0][k] = 1;
    // cout << a[1] << " " << b[1] << endl;
    For(i, 0, n - 1) For(j, 0, k) {
        if(a[i + 1] == -1 && b[i + 1] == -1) {
            For(p, 0, j) {
                if(j != k) {
                    f[i + 1][j - p] = (f[i + 1][j - p] + 1ll * (k - p) * f[i][j]) % P;
                }
                else if(p != k) {
                    f[i + 1][k] = (f[i + 1][k] + 1ll * (k - p) * f[i][j]) % P;
                }
            }
            For(p, 1, k - 1) f[i + 1][p] = (f[i + 1][p] + 1ll * (k - p) * f[i][j]) % P;
        }
        else if(a[i + 1] == -1) {
            For(p, 1, k) {
                if(b[i + 1] > p) f[i + 1][b[i + 1] - p] = (f[i + 1][b[i + 1] - p] + f[i][j]) % P;
                else if(j >= p - b[i + 1]) {
                    if(j != k) f[i + 1][j - (p - b[i + 1])] = (f[i + 1][j - (p - b[i + 1])] + f[i][j]) % P;
                    else f[i + 1][k] = (f[i + 1][k] + f[i][k]) % P;
                }
            }
        }
        else if(b[i + 1] == -1) {
            For(p, 1, k) {
                if(a[i + 1] < p) f[i + 1][p - a[i + 1]] = (f[i + 1][p - a[i + 1]] + f[i][j]) % P;
                else if(j >= a[i + 1] - p) {
                    if(j != k) f[i + 1][j - (a[i + 1] - p)] = (f[i + 1][j - (a[i + 1] - p)] + f[i][j]) % P;
                    else f[i + 1][k] = (f[i + 1][k] + f[i][k]) % P;
                }
            }
        }
        else {
            if(a[i + 1] < b[i + 1]) f[i + 1][b[i + 1] - a[i + 1]] = (f[i + 1][b[i + 1] - a[i + 1]] + f[i][j]) % P;
            else if(j >= a[i + 1] - b[i + 1]) {
                if(j != k) f[i + 1][j - (a[i + 1] - b[i + 1])] = (f[i + 1][j - (a[i + 1] - b[i + 1])] + f[i][j]) % P;
                else f[i + 1][k] = (f[i + 1][k] + f[i][k]) % P;
            }
        }
    }
    // cout << f[3][0] << endl;
    int res = 0;
    For(i, 0, k) res = (res + f[n][i]) % P;
    printf("%d\n", 1ll * res * bas % P);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
