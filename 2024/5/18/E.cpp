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
int T, n, a[maxn + 5], b[maxn + 5];

void mian() {
    read(n);
    For(i, 1, n) read(a[i]), b[a[i]] = i;
    int ok = -1;
    For(i, 1, n) if(b[i] != i) {
        if(b[b[i]] == i) {
            if(ok != -1 && i + b[i] != ok) {
                ok = 0;
                break;
            }
            ok = i + b[i];
        }
        else {
            ok = 0;
            break;
        }
    }
    int L = 1, R = n;
    while(b[L] == L && L <= n) L++;
    while(b[R] == R && R >= 1) R--;
    if(L >= R) {
        printf("%lld\n", 1ll * (2 * n + 1) * n);
        return;
    }
    int l = L + n, r = R + 1;
    LL res = 0;
    For(i, 1, l) res += 2 * n - max(i + 1, r) + 1;
    printf("%lld\n", res + (ok > 0));
    return;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
