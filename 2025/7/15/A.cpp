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
void read(T & x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define P 1000000007

#define maxn 200
int n, W[2], w[2][maxn + 5], iw[2][maxn + 5];

int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % P;
        x = 1ll * x * x % P;
        y >>= 1;
    }
    return res;
}

vector<int> vec;

int F[2 * maxn + 5], len = 0, inv[2 * maxn + 5];
int get_f(int o, int l, int r) {
    // cout << l << " " << r << endl;
    For(i, 1, n) iw[o][i] = fp(W[o] - w[o][i], P - 2);
    // cout << W[o] - w[o][1] << endl;
    len = 0;
    F[0] = 1;
    int mul = 1;
    For(i, 1, n) {
        if(w[o][i] * 2 <= W[o]) {
            if(l < w[o][i]) {
                F[len + 1] = P - 1ll * F[len] * iw[o][i] % P;
                Rof(i, len, 1) F[i] = (F[i] - 1ll * F[i - 1] * iw[o][i] % P + P) % P;
                len++;
            }
            else if(l < W[o] - w[o][i]) {
                mul = 1ll * mul * w[o][i] % P * iw[o][i] % P;
            }
            else {
                F[len + 1] = 1ll * F[len] * iw[o][i] % P;
                Rof(i, len, 1) F[i] = (1ll * F[i - 1] * iw[o][i] % P - 1ll * w[o][i] * iw[o][i] % P * F[i] % P + P) % P;
                F[0] = P - 1ll * w[o][i] * iw[o][i] % P * F[i] % P;
                len++;
            }
        }
        else {
            if(l < W[o] - w[o][i]) {
                F[len + 1] = P - 1ll * F[len] * iw[o][i] % P;
                Rof(i, len, 1) F[i] = (F[i] - 1ll * F[i - 1] * iw[o][i] % P * F[i] % P + P) % P;
                len++;

            }
            else if(l < w[o][i]) return 0;
            else {
                F[len + 1] = 1ll * F[len] * iw[o][i] % P;
                Rof(i, len, 1) F[i] = (1ll * F[i - 1] * iw[o][i] % P - 1ll * w[o][i] * iw[o][i] % P * F[i] % P + P) % P;
                F[0] = P - 1ll * w[o][i] * iw[o][i] % P * F[i] % P;
                len++;
            }
        }
    }
    // cout << iw[o][1] << endl;
    // cout << l << " " << r << endl;
    // For(i, 0, len) cout << F[i] << " "; cout << endl;
    int res = 0, R = 1, L = 1;
    For(i, 0, len) {
        R = 1ll * R * r % P;
        L = 1ll * L * l % P;
        res = (res + 1ll * (R - L + P) % P * inv[i + 1] % P * F[i] % P) % P;
    }
    // cout << 1ll * res * mul % P << endl;
    res = 1ll * res * mul % P;
    return res;
}

int sol(int o) {
    vec.clear();
    vec.pb(0); vec.pb(W[o]);
    For(i, 1, n) vec.pb(w[o][i]), vec.pb(W[o] - w[o][i]);
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    int res = 0;
    for(int i = 0; i + 1 < vec.size(); ++i) res = (res + get_f(o, vec[i], vec[i + 1])) % P;
    // cout << res << endl;
    return res;
}

int main() {
    For(i, 1, 2 * maxn) inv[i] = fp(i, P - 2);
    freopen("in.txt", "r", stdin);
    read(n); read(W[0]); read(W[1]);
    For(i, 1, n) For(o, 0, 1) read(w[o][i]);
    cout << sol(0) << endl;
    int res = 1ll * (W[0] - sol(0) + P) % P * (1ll * W[1] - sol(1) + P) % P;
    // cout << 1ll * sol(0) * sol(1) % P << endl;
    printf("%d\n", res);
    return 0;
}
