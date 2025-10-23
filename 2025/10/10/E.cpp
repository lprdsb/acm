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

#define maxn 10000000
int T, pri[maxn + 5], vis[maxn + 5], cnt = 0;

int n, m = 9;

LL get_f(int n, int x, int p) {
    LL res = Inf;
    LL s1 = 0, s2 = 0;
    while(n) {
        s1 += n / p;
        n /= p;
    }
    while(x) {
        s2 += x / p;
        x /= p;
    }
    assert(s1 != s2);
    int tmp = m, cnt = 0;
    // cout << s1 << " " << s2 << " " << p << "\n";
    while(tmp >= p) {
        tmp /= p;
        cnt++;
        // cout << s1 / cnt << " " << s2 / cnt << "\n";
        if(s1 / cnt != s2 / cnt) res = min(res, s2 / cnt);
    }
    // cout << res << endl;
    return res;
}

void mian() {
    read(n); read(m);
    if(!vis[n]) {
        puts("0");
        return;
    }
    LL res = 0;
    set<int> se;
    int tmp = n;
    while(vis[tmp]) {
        se.insert(vis[tmp]);
        tmp /= vis[tmp];
    }
    se.insert(tmp);
    Rof(i, n - 1, 1) {
        LL mn = inf;
        for(auto p : se) {
            // cout << p << endl;
            mn = min(mn, get_f(n, i, p));
        }
        // cout << i << " " << mn << "\n";
        res += mn;
        if(!vis[i]) break;

        int tmp = i;
        while(vis[tmp]) {
            se.insert(vis[tmp]);
            tmp /= vis[tmp];
        }
        se.insert(tmp);
    }
    printf("%lld\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    For(i, 2, maxn) {
        if(!vis[i]) pri[++cnt] = i;
        For(j, 1, cnt) {
            if(i * pri[j] > maxn) break;
            vis[i * pri[j]] = pri[j];
            if(i % pri[j] == 0) break;
        }
    }

    // cout << get_f(6, 5, 3) << "\n";
    read(T);
    while(T--) {
        mian();
    }
}
