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
int n, k, a[maxn + 5];
struct Node {
    int l, r;
};
#define mod 998244353
int sum[maxn + 5][24];
bool operator < (cst Node &_x, cst Node &_y) {
    if(_x.r - _x.l != _y.r - _y.l) return _x.r - _x.l < _y.r - _y.l;
    int now = 0;
    Rof(o, 22, 0) if(_x.l + now <= n && _y.l + now <= n && sum[_x.l + now][o] == sum[_y.l + now][o]) now |= 1 << o;
    if(_x.l == 6 && _x.r == 82) {
        // cout << sum[_x.l + 4][1] << " " << sum[_y.l + 4][1] << endl;
        // For(i, 0, now) cout << a[_x.l +i]; cout << endl;
        // For(i, 0, now) cout << a[_y.l + i]; cout << endl;
    }
    return _x.l + now <= n && _y.l + now <= n && a[_x.l + now] < a[_y.l + now];
}

vector<int> as1, as2;
#define P 1000000007

int pw[25];
void sol() {
    read(n); read(k);
    int cnt = 0;
    For(i, 1, n) {
        char c; cin >> c;
        a[i] = c - '0';
        cnt += a[i];
    }
    if(cnt <= k) {
        For(i, 1, cnt) as1.pb(1);
        return;
    }
    int now = n + 1, ok = cnt - k;
    while(ok) {
        now--;
        ok -= a[now];
    }
    if(n - now + 1 <= cnt) {
        For(i, 1, cnt) as1.pb(1);
        return;
    }
    ok = k;
    Rof(i, n, now) {
        if(a[i]) as1.pb(1);
        else if(ok) as1.pb(1), ok--;
        else as1.pb(0);
    }
    // for(auto i : as1) cout << i; cout << endl;
    For(i, 1, n) if(i < n - i + 1) swap(a[i], a[n - i + 1]);
    if(!k) return;
    k--;
    now = n; ok = cnt - k - 1;
    Node res = { 0, n };
    Rof(i, n, 1) {
        sum[i][0] = a[i] + 1;
        For(o, 1, 22) {
            sum[i][o] = 1ll * pw[o - 1] * sum[i][o - 1] % mod;
            int tem = i + (1 << (o - 1));
            if(tem <= n) sum[i][o] = (sum[i][o] + sum[tem][o - 1]) % mod;
        }
        // if(i == 10) cout << sum[10][1] << endl;
        ok -= a[i];
        while(ok < 0) {
            ok += a[now];
            now--;
        }
        if(!ok) {
            if(now - i + 2 <= cnt) {
                as1.resize(0);
                For(i, 1, cnt) as1.pb(1);
                return;
            }
            // if(i == 6) {
            //     // cout << i << " " << now + 1 << endl;
            //     cout << (Node{ i, now + 1 } < res) << endl;
            // }
            if(now != n && Node{ i, now + 1 } < res) res = { i, now + 1 };
        }
    }
    // cout << res.l << " " << res.r << endl;
    ok = k;
    Rof(i, res.r, res.l) {
        if(a[i]) as2.pb(1);
        else if(ok) as2.pb(1), ok--;
        else as2.pb(0);
    }
    // cout << as2.size() << endl;
    // for(auto i : as2) cout << i; cout << endl;
    if(as1.size() > as2.size()) swap(as1, as2);
    if(as1.size() == as2.size()) {
        int fl = 0;
        Rof(i, as1.size() - 1, 0) if(as1[i] != as2[i]) {
            fl = as2[i] <= as1[i];
            break;
        }
        if(fl) swap(as1, as2);
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    pw[0] = 13331;
    For(o, 1, 22) pw[o] = 1ll * pw[o - 1] * pw[o - 1] % mod;
    sol();
    int as = 0, now = 1;
    for(auto i : as1) {
        as = (as + 1ll * now * i % P) % P;
        now = 2ll * now % P;
    }
    printf("%d\n", as);
    return 0;
}
