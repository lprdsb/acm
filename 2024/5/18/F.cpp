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

#define maxn 500000
#define maxm 1000
int n, q, a[maxn + 5], b[maxn + 5], c[maxn + 5];
vector<int> da, db;
set<int> pri;
unordered_map<int, int> maa, mab;

LL f[maxm + 5][maxm + 5], g[maxm + 5][maxm + 5];
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

void sol(int x) {
    For(i, 2, 10000) {
        if(i * i > x) break;
        if(x % i == 0) {
            pri.insert(i);
            while(x % i == 0) x /= i;
        }
    }
    if(x != 1) pri.insert(x);
}

int as[maxn + 5];
set<pair<LL, int> > Q;
void soldp(LL bas) {
    For(i, 1, 10000) {
        if(i * i > a[1]) break;
        if(a[1] % i == 0) {
            da.pb(i);
            if(i * i != a[1]) da.pb(a[1] / i);
        }
    }
    For(i, 1, 10000) {
        if(i * i > b[1]) break;
        if(b[1] % i == 0) {
            db.pb(i);
            if(i * i != b[1]) db.pb(b[1] / i);
        }
    }
    sort(da.begin(), da.end());
    sort(db.begin(), db.end());
    For(i, 0, da.size() - 1) maa[da[i]] = i;
    For(i, 0, db.size() - 1) mab[db[i]] = i;
    For(i, 2, n) {
        g[maa[gcd(a[1], a[i])]][mab[gcd(b[1], b[i])]]++;

        g[maa[gcd(a[1], b[i])]][mab[gcd(b[1], a[i])]]++;
        f[maa[gcd(a[1], b[i])]][mab[gcd(b[1], a[i])]] += c[i];

        g[maa[gcd(a[1], gcd(a[i], b[i]))]][mab[gcd(b[1], gcd(a[i], b[i]))]]--;
        f[maa[gcd(a[1], gcd(a[i], b[i]))]][mab[gcd(b[1], gcd(a[i], b[i]))]] -= c[i];
    }
    for(auto p : pri) {
        Rof(i, da.size() - 1, 0) if(a[1] % (p * da[i]) == 0) {
            For(j, 0, db.size() - 1) {
                f[i][j] += f[maa[p * da[i]]][j];
                g[i][j] += g[maa[p * da[i]]][j];
            }
        }
    }
    for(auto p : pri) {
        Rof(i, db.size() - 1, 0) if(b[1] % (p * db[i]) == 0) {
            For(j, 0, da.size() - 1) {
                f[j][i] += f[j][mab[p * db[i]]];
                g[j][i] += g[j][mab[p * db[i]]];
            }
        }
    }
    set<pair<LL, int> > se;
    For(i, 0, da.size() - 1) For(j, 0, db.size() - 1) if(g[i][j] == n - 1) se.insert({ f[i][j], da[i] + db[j] });
    int now = 0;
    auto it = se.begin();
    for(auto [k, v] : Q) {
        while(it != se.end() && bas + it->fir <= k) {
            now = max(now, it->sec);
            it++;
        }
        as[v] = max(as[v], now);
    }
    For(i, 0, da.size() - 1) For(j, 0, db.size() - 1) f[i][j] = g[i][j] = 0;
    da.resize(0); db.resize(0);
}


int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(q);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) read(b[i]);
    For(i, 1, n) read(c[i]);
    For(i, 1, q) {
        LL x; read(x);
        Q.insert({ x, i });
    }
    sol(a[1]); sol(b[1]);

    soldp(0);
    swap(a[1], b[1]);
    soldp(c[1]);

    For(i, 1, q) printf("%d ", as[i]);
    return 0;
}
