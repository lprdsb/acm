#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define Mp make_pair
#define pb push_back
#define SZ(a) (int(a.size()))

typedef long long ll;
typedef double db;
typedef std::pair<int, int> pii;
typedef std::vector<int> vi;
#define debug(...) fprintf(stderr, __VA_ARGS__)
std::mt19937_64 gen(std::chrono::system_clock::now().time_since_epoch().count());
ll get(ll l, ll r) { std::uniform_int_distribution<ll> dist(l, r); return dist(gen); }

constexpr int P = 998244353;
using i64 = long long;
// assume -P <= x < 2P
int norm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}
template<class T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    Z(i64 x) : x(norm(x % P)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(P - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = i64(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Z &a) {
        i64 v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Z &a) {
        return os << a.val();
    }
};

constexpr int B = 44721, N = 1100, M = (B << 5) + 100;

clock_t ti, all1, all2; ll to;
int n, m, LL, a[N], b[N]; Z ans;
struct BIT {
    int tr[B + 100];
    void upd(int x, int v) {
        x += 5;
        for(; x <= B + 100; x += x&-x) tr[x] += v;
    }
    int qry(int x) {
        x += 5; int res = 0;
        for(; x; x -= x&-x) res += tr[x];
        return res;
    }
} bit;
signed main() {
	freopen("in.txt", "r", stdin);
    scanf("%d %d %d", &n, &m, &LL);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i]--;
    for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    for(int k = 1; k <= min(LL, B); k++) {
        for(int i = 1; i <= n; i++) ans += m * Z(a[i] / k);
        for(int j = 1; j <= m; j++) ans += n * Z(b[j] / k);
        for(int j = 1; j <= m; j++) bit.upd(b[j] % k, 1);
        for(int i = 1; i <= n; i++) {
            ans += m - bit.qry(k - a[i] % k - 1);
        }
        for(int j = 1; j <= m; j++) bit.upd(b[j] % k, -1);
    }
    // cout << ans << endl;
    if(LL > B) {
        for(int k = 1; k <= B; k++) {
            vector<Z> sum(m + 1, 0);
            for(int i = 1; i <= m; i++) {
                sum[i] = sum[i - 1] + (b[i] / k);
            }
            int L = m + 1, R = m;
            for(int i = 1; i <= n; i++) {
                while(L > 1 && 1ll * (B + 1) * k - a[i] <= b[L - 1]) L--, bit.upd(b[L] % k, 1);
                while(R >= L && 1ll * LL * k - a[i] <= b[R]) bit.upd(b[R] % k, -1), R--;
                ans += Z(m - R) * (LL - B);
                if(L <= R) {
                    ans += Z(R - L + 1) * (a[i] / k) + sum[R] - sum[L - 1];
                    ans += (R - L + 1) - bit.qry(k - a[i] % k - 1);
                    ans -= Z(R - L + 1) * B;
                }
            }
            while(R >= L) bit.upd(b[R] % k, -1), R--;
        }
    }
    cout << ans / m / LL + n << '\n';
    return 0;
}