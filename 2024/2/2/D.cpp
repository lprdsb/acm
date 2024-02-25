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

#define maxn 100000
int n, q, a[maxn + 5];
map<int, int> ma, ok;

int main() {
    //freopen("in", "r", stdin);
    read(n); read(q);
    // n = 100000;
    int mn = inf, mx = -inf;
    For(i, 1, n) {
        int x = i; read(x);
        a[i] = x;
        ma[x]++;
        mn = min(mn, x);
        mx = max(mx, x);
    }
    if(n == 1) {
        while(q--) {
            int M; read(M);
            puts("Yes");
        }
    }
    else {
        if(n <= 20) {
            For(kk, mx - 40000, mn + 40000) {
                LL res = 1;
                For(i, 1, n) {
                    res *= a[i] - kk;
                    if(abs(res) > inf || !res) break;
                }
                if(abs(res) <= inf || !res) ok[res] = 1;
            }
        }
        for(auto [k, v] : ma) {
            For(o, -2, 2) {
                int kk = k + o;
                // cout << kk << endl;
                int tot = 0;
                LL res = 1;
                auto it = ma.find(k);
                while(666) {
                    For(i, 1, it->sec) {
                        res *= it->fir - kk;
                        // cout << it->fir << " " << res << endl;
                        if(abs(res) > inf || !res) break;
                        // tot++;
                    }
                    if(abs(res) > inf || !res) break;
                    if(it == ma.begin()) break;
                    it--;
                }
                // cout << endl;
                it = ma.find(k);
                it++;
                while(it != ma.end()) {
                    For(i, 1, it->sec) {
                        res *= it->fir - kk;
                        if(abs(res) > inf || !res) break;
                        // tot++;
                    }
                    if(abs(res) > inf || !res) break;
                    it++;
                }
                if(abs(res) <= inf) ok[res] = 1;
            }
        }
        while(q--) {
            int M; read(M);
            if(ok[M]) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
