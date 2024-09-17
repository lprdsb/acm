#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

using Int = long long;

template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for(int i = 0; i < sz; ++i) { if(i >= 256) { os << ", ..."; break; } if(i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for(T i = a; i != b; ++i) cerr << *i << " "; cerr << endl; }
template <class T> bool chmin(T &t, const T &f) { if(t > f) { t = f; return true; } return false; }
template <class T> bool chmax(T &t, const T &f) { if(t < f) { t = f; return true; } return false; }
#define COLOR(s) ("\x1b[" s "m")

////////////////////////////////////////////////////////////////////////////////
template <unsigned M_> struct ModInt {
    static constexpr unsigned M = M_;
    unsigned x;
    constexpr ModInt() : x(0U) {}
    constexpr ModInt(unsigned x_) : x(x_ % M) {}
    constexpr ModInt(unsigned long long x_) : x(x_ % M) {}
    constexpr ModInt(int x_) : x(((x_ %= static_cast<int>(M)) < 0) ? (x_ + static_cast<int>(M)) : x_) {}
    constexpr ModInt(long long x_) : x(((x_ %= static_cast<long long>(M)) < 0) ? (x_ + static_cast<long long>(M)) : x_) {}
    ModInt &operator+=(const ModInt &a) { x = ((x += a.x) >= M) ? (x - M) : x; return *this; }
    ModInt &operator-=(const ModInt &a) { x = ((x -= a.x) >= M) ? (x + M) : x; return *this; }
    ModInt &operator*=(const ModInt &a) { x = (static_cast<unsigned long long>(x) * a.x) % M; return *this; }
    ModInt &operator/=(const ModInt &a) { return (*this *= a.inv()); }
    ModInt pow(long long e) const {
        if(e < 0) return inv().pow(-e);
        ModInt a = *this, b = 1U; for(; e; e >>= 1) { if(e & 1) b *= a; a *= a; } return b;
    }
    ModInt inv() const {
        unsigned a = M, b = x; int y = 0, z = 1;
        for(; b; ) { const unsigned q = a / b; const unsigned c = a - q * b; a = b; b = c; const int w = y - static_cast<int>(q) * z; y = z; z = w; }
        assert(a == 1U); return ModInt(y);
    }
    ModInt operator+() const { return *this; }
    ModInt operator-() const { ModInt a; a.x = x ? (M - x) : 0U; return a; }
    ModInt operator+(const ModInt &a) const { return (ModInt(*this) += a); }
    ModInt operator-(const ModInt &a) const { return (ModInt(*this) -= a); }
    ModInt operator*(const ModInt &a) const { return (ModInt(*this) *= a); }
    ModInt operator/(const ModInt &a) const { return (ModInt(*this) /= a); }
    template <class T> friend ModInt operator+(T a, const ModInt &b) { return (ModInt(a) += b); }
    template <class T> friend ModInt operator-(T a, const ModInt &b) { return (ModInt(a) -= b); }
    template <class T> friend ModInt operator*(T a, const ModInt &b) { return (ModInt(a) *= b); }
    template <class T> friend ModInt operator/(T a, const ModInt &b) { return (ModInt(a) /= b); }
    explicit operator bool() const { return x; }
    bool operator==(const ModInt &a) const { return (x == a.x); }
    bool operator!=(const ModInt &a) const { return (x != a.x); }
    friend std::ostream &operator<<(std::ostream &os, const ModInt &a) { return os << a.x; }
};
////////////////////////////////////////////////////////////////////////////////

constexpr unsigned MO = 998244353;
using Mint = ModInt<MO>;

using Pair = pair<Mint, Mint>;
Pair operator+(const Pair &a, const Pair &b) { return make_pair(a.first + b.first, a.second + b.second); }
Pair operator-(const Pair &a, const Pair &b) { return make_pair(a.first - b.first, a.second - b.second); }
Pair operator*(const Pair &a, const Pair &b) { return make_pair(a.first * b.first, a.first * b.second + a.second * b.first); }
Pair operator*(const Pair &a, Mint k) { return make_pair(a.first * k, a.second * k); }
Pair operator*(Mint k, const Pair &a) { return make_pair(k * a.first, k * a.second); }
Pair &operator+=(Pair &a, const Pair &b) { return a = a + b; }
Pair &operator-=(Pair &a, const Pair &b) { return a = a - b; }
Pair &operator*=(Pair &a, const Pair &b) { return a = a * b; }
Pair &operator*=(Pair &a, Mint k) { return a = a * k; }
constexpr Pair ZERO(0, 0);


// (without edge property)
// sub[u]: inside subtree at u, rooted at u
// bus[u]: outside subtree at u, rooted at par[u]
// tot[u]: rooted at u
// T: monoid representing information of a subtree.
//   T::init()  should assign the identity.
//   T::pull(const T &l, const T &r)  should assign the product.
//   T::up(int u)  should attach vertex u to the product of the subtrees.
template <class T> struct ForestDP {
    int n;
    vector<vector<int>> graph;
    vector<int> par;
    vector<T> sub, bus, tot;

    ForestDP() : n(0) {}
    explicit ForestDP(int n_) : n(n_), graph(n_) {}
    void ae(int u, int v) {
        assert(0 <= u); assert(u < n);
        assert(0 <= v); assert(v < n);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    void run() {
        par.assign(n, -2);
        sub.resize(n);
        bus.resize(n);
        tot.resize(n);
        for(int u = 0; u < n; ++u) if(par[u] == -2) {
            dfs0(u, -1);
            dfs1(u, -1);
        }
    }
    void dfs0(int u, int p) {
        par[u] = p;
        const int deg = graph[u].size();
        int w = -1;
        for(int j = deg; --j >= 0; ) {
            const int v = graph[u][j];
            if(p != v) {
                dfs0(v, u);
                if(~w) {
                    bus[v].pull(sub[v], bus[w]);
                }
                else {
                    bus[v] = sub[v];
                }
                w = v;
            }
        }
        if(~w) {
            sub[u] = bus[w];
        }
        else {
            sub[u].init();
        }
        sub[u].up(u);
    }
    void dfs1(int u, int p) {
        const int deg = graph[u].size();
        int v = -1;
        for(int j = 0; j < deg; ++j) {
            const int w = graph[u][j];
            if(p != w) {
                if(~v) {
                    bus[v].pull(tot[v], bus[w]);
                    bus[v].up(u);
                    tot[w].pull(tot[v], sub[v]);
                    dfs1(v, u);
                }
                else {
                    if(~p) {
                        tot[w] = bus[u];
                    }
                    else {
                        tot[w].init();
                    }
                }
                v = w;
            }
        }
        if(~v) {
            bus[v] = tot[v];
            bus[v].up(u);
            tot[u].pull(tot[v], sub[v]);
            dfs1(v, u);
        }
        else {
            if(~p) {
                tot[u] = bus[u];
            }
            else {
                tot[u].init();
            }
        }
        tot[u].up(u);
    }
};


// max dep -> (\sum 1, \sum # (max dep vertex))
struct Data {
    vector<Pair> fs;
    void init() {
        fs = { Pair(1, 0) };
    }
    void pull(const Data &a, const Data &b) {
        const int lenA = a.fs.size();
        const int lenB = b.fs.size();
        const int len = max(lenA, lenB);
        fs.assign(len, ZERO);
        Mint sumA = 0;
        Mint sumB = 0;
        for(int i = 0; i < len; ++i) {
            if(i < lenA) fs[i] += a.fs[i] * sumB;
            if(i < lenB) fs[i] += sumA * b.fs[i];
            if(i < lenA && i < lenB) fs[i] += a.fs[i] * b.fs[i];
            if(i < lenA) sumA += a.fs[i].first;
            if(i < lenB) sumB += b.fs[i].first;
        }
        // cerr<<"pull "<<a.fs<<" * "<<b.fs<<" = "<<fs<<endl;
    }
    void up(int) {
        const int len = fs.size();
        fs.push_back(ZERO);
        fs[0] *= Pair(1, 1);
        for(int i = len; --i >= 0; ) {
            fs[i + 1] += fs[i];
        }
    }
};


/*
  even diam: vertex - edge
  odd diam: edge
*/

int N;
vector<int> A, B;

Mint dp[2010][3];
void add(const Data &t) {
    // cerr<<"  [add] "<<t.fs<<endl;
    const int len = t.fs.size();
    Mint sum0 = 0;
    for(int d = 0; d <= (N - 1) / 2; ++d) {
        if(d < len) sum0 += t.fs[d].first;
        for(int k = 2; k >= 0; --k) {
            if(d < len && k < 2) dp[d][k + 1] += dp[d][k] * t.fs[d].second;
            dp[d][k] *= sum0;
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    for(; ~scanf("%d", &N); ) {
        A.resize(N - 1);
        B.resize(N - 1);
        for(int i = 0; i < N - 1; ++i) {
            scanf("%d%d", &A[i], &B[i]);
            --A[i];
            --B[i];
        }

        ForestDP<Data> f(N);
        for(int i = 0; i < N - 1; ++i) {
            f.ae(A[i], B[i]);
        }
        f.run();

        Mint ans = 0;
        for(int u = 0; u < N; ++u) {
            // cerr<<"u = "<<u<<endl;
            for(int d = 0; d <= (N - 1) / 2; ++d) {
                dp[d][0] = 1;
                dp[d][1] = 0;
                dp[d][2] = 0;
            }
            dp[0][1] = 1;
            if(~f.par[u]) {
                add(f.bus[u]);
            }
            for(const int v : f.graph[u]) if(f.par[u] != v) {
                add(f.sub[v]);
            }
            for(int d = 0; d <= (N - 1) / 2; ++d) {
                // cerr<<"  dp["<<d<<"] = ";pv(dp[d],dp[d]+3);
                ans += dp[d][2];
            }
        }
        printf("%u\n", ans.x);
    }
    return 0;
}
