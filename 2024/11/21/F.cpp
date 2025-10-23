#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define LL long long
#define i128 __int128_t
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
void read(T &x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

LL fp(LL x, LL y, LL P) {
    LL res = 1;
    while(y) {
        if(y & 1) res = (i128)res * x % P;
        x = (i128)x * x % P;
        y >>= 1;
    }
    return res;
}

LL gcd(LL x, LL y) { return y ? gcd(y, x % y) : x; }
LL pri_bas[8] = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 };
int Miller_Rabin(LL x) {
    if(x < 3 || x % 2 == 0) return x == 2;
    LL u = x - 1;
    int t = 0;
    while(u % 2 == 0) u >>= 1, t++;
    For(o, 0, 3) {
        LL now = fp(pri_bas[o], u, x);
        if(now <= 1) continue;
        For(i, 1, t) {
            if(now == x - 1) break;
            if(i == t) return 0;
            now = (i128)now * now % x;
            if(now == 1) return 0;
        }
    }
    return 1;
}

#define maxm 5000000
int pri[maxm + 5], vis[maxm + 5], cnt = 0;
unordered_map<LL, LL> ma1;
LL Pollard_Rho(LL x) {
    if(x <= maxm) return vis[x];
    if(ma1.count(x)) return ma1[x];
    if(x == 4) return ma1[x] = 2;
    if(Miller_Rabin(x)) return ma1[x] = x;
    default_random_engine de;
    uniform_int_distribution<LL> rd(1, x - 1);
    while(666) {
        LL c = rd(de);
        auto f = [&](LL _x) {return ((i128)_x * _x + c) % x;};
        LL s = 0, t = 0;
        while(666) {
            LL p = 1;
            For(i, 1, 128) {
                s = f(s);
                t = f(f(t));
                if(s == t) break;
                LL tem = (i128)p * abs(s - t) % x;
                if(!tem) break;
                p = tem;
            }
            LL gc = gcd(p, x);
            if(gc > 1) return ma1[x] = gc;
            if(s == t) break;
        }
    }
}

#define maxn 50000
int n;

vector<LL> d[maxn + 5];
void sol(LL x, vector<LL> &v) {
    if(x == 1) return;
    LL tmp = Pollard_Rho(x);
    if(x == tmp) {
        v.pb(x);
        return;
    }
    while(x % tmp == 0) x /= tmp;
    sol(x, v); sol(tmp, v);
}

int as[maxn + 5], res = inf, aa[10];
LL a[maxn + 5];

unordered_map<LL, int> ma;

int main() {
    vis[1] = 1;
    For(i, 2, maxm) {
        if(!vis[i]) pri[++cnt] = i, vis[i] = i;
        for(int j = 1; j <= cnt && i * pri[j] <= maxm; ++j) {
            vis[i * pri[j]] = pri[j];
            if(i % pri[j] == 0) break;
        }
    }
    // freopen("in.txt", "r", stdin);
    read(n);
    For(i, 1, n) {
        LL x; read(x); a[i] = x;
        sol(x, d[i]);
        sort(d[i].begin(), d[i].end());
        d[i].erase(unique(d[i].begin(), d[i].end()), d[i].end());
        for(auto v : d[i]) ma[v]++;
    }
    int t = 0;
    for(auto [k, v] : ma) if(2 * v >= n) {
        LL gc = 0;
        For(i, 1, n) if(a[i] % k != 0) gc = gcd(gc, a[i]);
        if(gc == 0) {
            aa[3] = 0;
            res = abs(n - n / 2 - n / 2);
            For(i, 1, n) as[i] = 0;
            For(i, 1, n / 2) as[i] = 1;
            break;
        }
        else if(gc != 1) {
            int mx[2] = { -1, 0 };
            vector<LL> V;
            sol(gc, V);
            sort(V.begin(), V.end());
            V.erase(unique(V.begin(), V.end()), V.end());
            for(auto v1 : V) {
                // t++;
                // assert(t <= 1500);
                int tmp = 0;
                For(i, 1, n) if(a[i] % k == 0 && a[i] % v1 == 0) tmp++;
                if(tmp > mx[1] || mx[0] == -1) mx[0] = v1, mx[1] = tmp;
            }
            if(mx[0] != -1) {
                int ok = 2 * v - n;
                ok -= 2 * mx[1];
                if(ok < 0) ok = (abs(ok) % 2) ? 1 : 0;
                if(ok < res) {
                    res = ok;
                    int cnt = (2 * v - n - ok) / 2;
                    aa[0] = k; aa[1] = mx[0]; aa[2] = cnt; aa[3] = 1;
                }
            }
        }
    }
    if(res == inf) puts("-1");
    else {
        if(aa[3]) {
            For(i, 1, n) {
                if(a[i] % aa[0] == 0) {
                    if(a[i] % aa[1] == 0) {
                        as[i] = aa[2] != 0;
                        if(aa[2]) aa[2]--;
                    }
                    else as[i] = 0;
                }
                else as[i] = 1;
            }
        }
        For(i, 1, n) printf("%d ", as[i] + 1);
    }
    return 0;
}

