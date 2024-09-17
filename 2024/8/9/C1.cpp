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
using Z = Mint<P>;

struct Data {
    int a[50];
};

struct Hsh {
    int operator () (cst Data &x) cst {
        Z tmp = 0;
        For(i, 1, 32) tmp = tmp * 13331 + x.a[i];
        return tmp.x;
    }
};

struct Equal {
    int operator () (cst Data &x, cst Data &y) cst {
        For(i, 1, 32) if(x.a[i] != y.a[i]) return 0;
        return 1;
    }
};

unordered_map<Data, int, Hsh, Equal> ma;

int n = 32, m = 512, m0, w;

#define maxn 32
vector<pair<int, LL> > ch[maxn + 5];

int cnt = 0;
LL bas[65];
void ins(LL x) {
    // cout << x << endl;
    Rof(o, 60, 0) {
        if((x >> o) & 1) x ^= bas[o];
        if((x >> o) & 1) {
            bas[o] = x, cnt++;
            break;
        }
    }
}

int vis[maxn + 5];
int sz = 0, szm = 0;
LL val[maxn + 5];
void dfs(int u) {
    vis[u] = 1;
    sz++;
    szm += ch[u].size();
    for(auto [v, C] : ch[u]) {
        if(!vis[v]) {
            val[v] = val[u] ^ C;
            dfs(v);
        }
        else ins(val[u] ^ val[v] ^ C);
    }
}

#define maxm 600
Z f[maxm + 5][9005];

Data mask[9005];
int tot = 0, totm = 0;
void dfs1(int pos, Data &now, int sum) {
    if(!sum) {
        mask[++tot] = now;
        ma[now] = tot;
        return;
    }
    if(sum < pos) return;
    For(i, 0, sum / pos) {
        now.a[pos] = i;
        dfs1(pos + 1, now, sum);
        now.a[pos] = 0;
        sum -= pos;
    }
}

Z c[maxm + 5][maxm + 5];
vector<pair<int, Z> > ok[9005];

Z chk(int x, int y) {
    int fl = 0;
    Z res = 1;
    while(x || y) {
        if(x % 33 < y % 33) return 0;
        if(x % 33) {
            if(!fl) {
                if(!(y % 33)) return 0;
                res *= c[x % 33 - 1][y % 33 - 1];
            }
            else res *= c[x % 33][y % 33];
            fl = 1;
        }
        x /= 33; y /= 33;
    }
    return res;
}

Z h[maxm + 5][65];
Z sol(int N, int M) {
    h[0][cnt] = 1;
    For(i, 0, N - 1) For(j, 0, M) if(h[i][j].x) {
        h[i + 1][j] += h[i][j] * fp(Z{ 2 }, j);
        h[i + 1][j + 1] += h[i][j] * (fp(Z{ 2 }, M) - fp(Z{ 2 }, j));
    }
    return h[N][M];
}

int sum[9005];
int main() {
    // freopen("in.txt", "r", stdin);
    c[0][0] = 1;
    For(i, 1, maxm) {
        c[i][0] = 1;
        For(j, 1, i) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
    read(n); read(m); read(m0); read(w);
    For(i, 1, m0) {
        int u, v; LL C; read(u); read(v); read(C);
        ch[u].pb({ v, C }); ch[v].pb({ u, C });
    }

    Data tmp = {};
    dfs1(1, tmp, n);
    // cout << tot << endl;

    int cpn = 0;
    tmp = {};
    For(i, 1, n) if(!vis[i]) {
        cpn++;
        dfs(i);
        tmp.a[sz]++;
        totm += sz * (sz - 1) / 2 - szm / 2;
        sz = szm = 0;
    }

    f[m0][ma[tmp]] = 1;

    // cout << tot << endl;
    // For(i, 1, tot) {
    //     cout << i << "-------------" << ma[mask[i]] << endl;
    //     For(j, 1, n) cout << mask[i].a[j] << " "; cout << endl;
    // }
    For(o, 1, tot) {
        Data tem = mask[o];
        For(j, 1, 32) sum[o] += tem.a[j] * j * (j - 1) / 2;
        For(i, 1, 32) if(tem.a[i]) {
            if(tem.a[i] >= 2) {
                Z opt = c[tem.a[i]][2] * i * i;
                tem.a[i] -= 2;
                tem.a[2 * i] += 1;
                ok[o].pb({ ma[tem], opt });
                tem.a[2 * i] -= 1;
                tem.a[i] += 2;
            }
            For(j, i + 1, 32) if(tem.a[j]) {
                Z opt = 1ll * tem.a[i] * tem.a[j] * i * j;
                tem.a[i] -= 1;
                tem.a[j] -= 1;
                tem.a[i + j] += 1;
                ok[o].pb({ ma[tem], opt });
                tem.a[i + j] -= 1;
                tem.a[j] += 1;
                tem.a[i] += 1;
            }
        }
    }
    // cout << f[0][5].x << endl;
    // for(auto [p, q] : ok[2]) cout << p << " " << q.x << endl;

    For(i, m0, m - 1) For(j, 1, tot) if(f[i][j].x) {
        f[i + 1][j] += f[i][j] * (sum[j] - i);
        for(auto [p, q] : ok[j]) f[i + 1][p] += f[i][j] * q;
    }
    tmp = {};
    tmp.a[n] = 1;

    Z res = f[m][ma[tmp]];
    For(i, 1, m - m0) res /= i;
    // cout << sol(m - m0 - (cpn - 1), w).x << endl;
    res *= sol(m - m0 - (cpn - 1), w) * fp(Z{ 2 }, (cpn - 1) * w);
    printf("%d\n", res.x);
}
