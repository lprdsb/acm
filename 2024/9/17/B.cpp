#include<bits/stdc++.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(LL i = (a), en = (b); i >= en; --i)
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
#define maxn 1000000
using namespace std;

LL pri[maxn + 5], cnt = 0, vis[maxn + 5];

template<class T>
T fp(T x, LL y) {
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
    Mint(LL _x) : x{ norm(_x % P) } {}
    int norm(LL _x) {
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

class Sieve {
    public:
    LL to[maxn + 5], tot = 0, k_n[maxn + 5];
    LL N;
    LL sum_f_p[maxn + 5];
    unordered_map<LL, int> id;
    vector<bool> vG[maxn + 5];
    vector<LL> G[maxn + 5];
    LL get_g(LL x) {
        //
        return 1;
    }
    Sieve() {}
    LL get_G(int n_id, int k) {
        if(pri[k] > to[n_id]) return get_g(1);
        if(k == 1) return to[n_id];
        if(1ll * pri[k - 1] * pri[k - 1] > to[n_id]) return get_G(n_id, k_n[n_id] + 1) - (sum_f_p[k - 1] - sum_f_p[k_n[n_id]]);
        return G[n_id][k];
    }
    void init(LL _N) {
        N = _N;
        tot = 0;
        For(i, 1, N) {
            ++tot;
            id[to[tot] = N / i] = tot;
            i = N / (N / i);
        }
        int now = cnt;
        For(i, 1, tot) {
            while(1ll * pri[now] * pri[now] > to[i]) now--;
            G[i].clear();
            G[i].resize(now + 5, 0);
            vG[i].clear();
            vG[i].resize(now + 5, 0);
            k_n[i] = now;
        }
        For(i, 1, cnt) sum_f_p[i] = sum_f_p[i - 1] + get_g(pri[i]);
        For(i, 2, k_n[1] + 1) {
            For(j, 1, tot) {
                if(1ll * pri[i - 1] * pri[i - 1] > to[j]) break;
                vG[j][i] = 1;
                G[j][i] = get_G(j, i - 1) - get_g(pri[i - 1]) * get_G(id[to[j] / pri[i - 1]], i - 1);
            }
        }
    }
    LL get_s(LL n) {
        return k_n[id[n]] + get_G(id[n], k_n[id[n]] + 1);
    }
} sieve;

template <class T>
void read(T &x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int main() {
    // freopen("in.txt", "r", stdin);
    For(i, 2, maxn) {
        if(!vis[i]) pri[++cnt] = i;
        for(int j = 1; j <= cnt && i * pri[j] <= maxn; ++j) {
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
        }
    }
    LL n = 4;
    read(n);
    sieve.init(n);
    // if(n == 84848352911ll) {
    //     cout << "asd" << endl;
    //     return 0;
    // }
    Z res = 1;
    for(LL i = 1; i <= n; ++i) {
        LL now = n / i, to = n / now;
        if(now <= 2) break;
        LL cntp = sieve.get_s(now) - sieve.get_s(now / 2);
        LL cnt = cntp + 1 + (now - cntp - 1 != 0);
        res *= fp(fp(Z{ now }, cnt - 2) * Z { (now - cntp - 1) ? (now - cntp - 1) : 1 }, to - i + 1);
        i = to;
    }
    cout << res.x << endl;
    return 0;
}

