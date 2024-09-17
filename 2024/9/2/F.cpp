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

#define maxn 400000
int T, n, a[maxn + 5];

int gcd(int x, int y) { return y ? gcd(y, x % y) : abs(x); }

void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    LL res = 0, now = 1, cnt = 0;
    For(i, 1, n) {
        if(a[i] != a[i - 1]) cnt = 0;
        cnt++;
        res += cnt;
    }
    Rof(i, n, 2) {
        a[i] -= a[i - 1];
    }
    For(i, 2, n) while(a[i] && a[i] % 2 == 0) a[i] >>= 1;
    For(i, 2, n) {
        int gc = a[i];
        Rof(j, i, 2) {
            gc = gcd(gc, a[j]);
            if(gc == a[j] && j != i) break;
            a[j] = gc;
            if(gc == 1) {
                now = j;
                break;
            }
        }
        // cout << i << " " << now << " " << a[i] << endl;
        res += now - 1;
    }
    printf("%lld\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
