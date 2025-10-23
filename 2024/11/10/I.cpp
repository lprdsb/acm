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

#define maxn 1000
int T, n;
pair<int, int> pa[maxn + 5], vec[maxn + 5];

void mian() {
    read(n);
    For(i, 1, n) read(pa[i].fir), read(pa[i].sec);
    int q; read(q);
    while(q--) {
        int x, y; read(x); read(y);
        For(i, 1, n) {
            vec[i] = { pa[i].fir - x, pa[i].sec - y };
            if(vec[i].sec < 0) {
                vec[i].fir = -vec[i].fir;
                vec[i].sec = -vec[i].sec;
            }
        }
        sort(vec + 1, vec + n + 1, [](pair<int, int> pa1, pair<int, int> pa2) {
            return 1ll * pa1.fir * pa2.sec - 1ll * pa1.sec * pa2.fir > 0;
            });
        // For(i, 1, n) cout << vec[i].fir << " " << vec[i].sec << endl;
        int pre = 1, res = 0;
        For(i, 1, n) if(1ll * vec[i].fir * vec[i - 1].sec - 1ll * vec[i].sec * vec[i - 1].fir) {
            res += (i - pre) / 2;
            pre = i;
            // cout << i << " " << res << endl;
        }
        res += (n + 1 - pre) / 2;
        printf("%d\n", res);
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
