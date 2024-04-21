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

#define maxn 200000
int n, a[maxn + 5], b[maxn + 5];

void sol(int ty) {
    For(i, 1, n - 1) {
        a[i] = max(0, a[i] - a[i - 1]);
        if(!a[i] && ty) return;
    }
    a[0] = max(0, a[0] - a[n - 1]);
    if(!a[0] && ty) return;
}

int main() {
    // freopen("in.txt", "r", stdin);
    int T; read(T);
    while(T--) {
        read(n);
        For(i, 0, n - 1) read(a[i]), b[i + 1] = a[i];
        For(i, 1, 3000) sol(0); sol(1);
        For(i, 0, n - 1) {
            int a1 = a[i], a2 = a[(i + 1) % n], a3 = a[(i + 2) % n], a4 = a[(i + 3) % n];
            if(a1 || !a2 || !a3) continue;
            if(a4 && n > 3) {
                // if(n >= 4 && a[(i + 4) % n]) {
                //     printf("%d$", n);
                //     For(i, 1, n) printf("%d$", b[i]);
                //     return 0;
                // }
                int tem = a3 / a2;
                if(a4 - 1ll * tem * a3 + (__int128)(1 + tem) * tem / 2 * a2 <= 0) a[(i + 3) % n] = 0;
            }
            a[(i + 2) % n] = 0;
        }
        vector<int> as;
        For(i, 0, n - 1) if(a[i]) as.pb(i + 1);
        printf("%d\n", as.size());
        for(auto i : as) printf("%d ", i); puts("");
    }
}
