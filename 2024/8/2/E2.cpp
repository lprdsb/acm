#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
// #define LL long long
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


template<class T>
T fp(T x, int y) {
    T asi = 1;
    while(y) {
        if(y & 1) asi *= x;
        x *= x;
        y >>= 1;
    }
    return asi;
}

template<int P>
struct Mint {
    int x;
    Mint() { x = 0; }
    Mint(int _x) : x{ norm(_x % P) } {}
    int norm(int _x) {
        if(_x < 0) _x += P;
        if(_x >= P) _x -= P;
        return _x;
    }
    Mint inv() { return fp(*this, P - 2); }
    Mint operator - () { return { P - x }; }
    Mint& operator += (Mint _x) & {
        x = norm(x + _x.x);
        return *this;
    }
    Mint& operator -= (Mint _x) & {
        x = norm(x - _x.x);
        return *this;
    }
    Mint& operator *= (Mint _x) & {
        x = 1ll * x * _x.x % P;
        return *this;
    }
    Mint& operator /= (Mint _x) & { return *this *= _x.inv(); }
    friend Mint operator + (Mint _x, Mint _y) { return _x += _y; }
    friend Mint operator - (Mint _x, Mint _y) { return _x -= _y; }
    friend Mint operator * (Mint _x, Mint _y) { return _x *= _y; }
    friend Mint operator / (Mint _x, Mint _y) { return _x /= _y; }
    friend bool operator == (Mint _x, Mint _y) { return _x.x == _y.x; }
};

const int P = 998244353;
using LL = Mint<P>;

#define maxn 500
#define mod 998244353
int n, k;
LL pwk[maxn + 5];
int b[maxn + 5], tot = 0;
LL f[maxn + 5], del[maxn + 5][maxn + 5];
LL sol(int len) {
    For(i, 1, n) f[i] = 0;
    LL res = 0;
    For(i, len, n) {
        f[i] += pwk[i - len];
        // if(f[i] >= mod) f[i] -= mod;
        For(j, i + 1, n) {
            if(j - i >= len) {
                f[j] -= f[i] * pwk[j - i - len];
            }
            else if(b[len + i - j]) {
                f[j] -= f[i];
            }
        }
        res += f[i] * pwk[n - i];
    }
    // cout << "len: " << len << endl;
    // For(i, 1, len) cout << b[i] << " ";
    // cout << endl << res << endl;
    // if(len == 1) cout << res << endl;
    return res;
}
LL res = 0;
void dfs(int now, LL cnt) {
    tot++;
    res += sol(now) * cnt;
    For(i, now + 1, n) del[now][i] = 0;
    For(i, now + 1, n) {
        LL nc = 0;
        if(2 * now > i) {
            if(b[2 * now - i]) {
                nc = cnt - del[now][i] + mod;
                For(j, i + 1, n) {
                    if(2 * i > j) {
                        if(b[2 * i - j]) {
                            del[now][j] += nc;
                        }
                    }
                    else {
                        del[now][j] += nc * pwk[(j - 2 * i + 1) / 2];
                    }
                }
            }
        }
        else {
            nc = cnt * pwk[(i - 2 * now + 1) / 2] - del[now][i] + mod;
            // if(now == 1 && i == 3) cout << del[now][i] << endl;
            For(j, i + 1, n) {
                if(2 * i > j) {
                    if(b[2 * i - j]) {
                        del[now][j] += nc;
                    }
                }
                else {
                    del[now][j] += nc * pwk[(j - 2 * i + 1) / 2];
                }
            }
        }
        b[i] = 1;
        if(nc.x) dfs(i, nc);
        b[i] = 0;
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(k);
    pwk[0] = 1;
    For(i, 1, maxn) pwk[i] = pwk[i - 1] * k;
    b[1] = 1;
    dfs(1, k);
    cout << res.x << endl;
    // cout << tot << endl;
}
