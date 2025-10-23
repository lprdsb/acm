#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
#define int ll
using namespace std;
typedef long long ll;

// const int N = 5e5 + 7;
const int P = 998244353, gi = 3, ig = 332748118;
const int N = 1e6 + 7;
char s[N], t[N], n, m;
int a[N], b[N], x[N];
int len, lim;

namespace POLY {
    int w[N];
    int rev[N];
    int qw(int a, int b) {
        int ans = 1;for(;b;a = (ll)a * a % P, b >>= 1)if(b & 1)ans = (ll)ans * a % P;
        return ans;
    }
    void pre(int deg) {
        lim = 1;len = 0;
        while(lim < deg + 1)lim <<= 1, ++len;
        fs(i, 0, lim - 1)rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (len - 1));
    }
    void init() {
        w[0] = 1;
    }
    void NTT(int *a, int lim, int type) {
        int ng = type ? gi : ig;
        fs(i, 0, lim - 1)if(i < rev[i])swap(a[i], a[rev[i]]);
        for(int l = 1, le = 2;l < lim;l <<= 1, le <<= 1) {
            w[1] = qw(ng, (P - 1) / le);
            fs(i, 2, l - 1)w[i] = (ll)w[i - 1] * w[1] % P;
            for(int i = 0;i < lim;i += le) {
                int *f1 = a + i, *f2 = f1 + l;
                for(int k = 0;k < l;++k) {
                    int y = (ll)w[k] * f2[k] % P;
                    f2[k] = (f1[k] - y) % P;
                    f1[k] = (f1[k] + y) % P;
                }
            }
        }
        fs(i, 0, lim - 1)(a[i] < 0) && (a[i] += P);
        if(type)return;
        int iv = P - (P - 1) / lim;
        fs(i, 0, lim - 1)a[i] = (ll)a[i] * iv % P;
    }
}

void solve() {
    scanf("%s", &s);scanf("%s", &t);
    n = strlen(s);--n;m = strlen(t);--m;
    fs(i, 0, n)a[i] = s[i] - '0';
    fs(i, 0, m)b[i] = t[i] - '0';
    reverse(a, a + n + 1);reverse(b, b + m + 1);
    POLY::pre(n + m);
    POLY::NTT(a, lim, 1);POLY::NTT(b, lim, 1);
    fs(i, 0, lim - 1)x[i] = (ll)a[i] * b[i] % P, a[i] = 0, b[i] = 0;
    POLY::NTT(x, lim, 0);
    int mx = lim + 100;
    // fn(i, mx, 0)cout << x[i];
    // cout << endl;
    int i = 0;
    while(i <= mx) {
        if(x[i] > 0) {
            x[i + 2] -= x[i] / 2;
            x[i] = x[i] % 2;
            if(x[i + 2] != 0)mx = max(mx, i + 2);
        }
        else if(x[i] < 0) {
            x[i + 2] -= (x[i] - 1) / 2;
            x[i] -= (x[i] - 1) / 2 * 2;
            if(x[i + 2] != 0)mx = max(mx, i + 2);
        }
        // int dta = min(x[i + 2], x[i] / 2);
        // x[i + 2] -= dta, x[i] -= dta * 2;
        // int tp = x[i];x[i] = 0;
        // if(tp & 1)x[i] = 1;
        // fs(p, 1, 19) {
        //     if((tp >> p) & 1) {
        //         if(p % 2 == 0) {
        //             x[i + 2 * p]++;
        //             mx = max(i + 2 * p, mx);
        //         }
        //         else {
        //             x[i + 2 * p]++;
        //             x[i + 2 * p + 2]++;
        //             mx = max(i + 2 * p + 2, mx);
        //         }
        //     }
        // }
        ++i;
        // cout << i << endl;
    }
    while(x[mx] == 0 && mx > 0)--mx;
    fn(i, mx, 0)printf("%lld", x[i]), x[i] = 0;
    printf("\n");
}

signed main() {
    // freopen("inp.txt", "r", stdin);
    POLY::init();
    int T = 1;
    scanf("%lld", &T);
    while(T--) {
        solve();
    }
}