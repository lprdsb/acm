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
int T, n, a[maxn + 5], m, b[maxn + 5];

int st[maxn + 5];
void mian() {
    read(n);
    m = 0;
    For(i, 1, n) {
        char c; cin >> c;
        int x = c - '0';
        if(m >= 2) {
            if(x == a[m] && x == a[m - 1]) m--;
            else a[++m] = x;
        }
        else a[++m] = x;
    }
    if(m <= 1) {
        puts("1");
        return;
    }
    n = m;
    int now = 0;
    m = 0;
    a[0] = -1;
    For(i, 1, n) {
        if(a[i] != a[i - 1]) now++;
        else {
            b[++m] = now;
            now = 1;
        }
    }
    b[++m] = now;
    if(!m) {
        puts("1");
        return;
    }
    // For(i, 1, m) cout << b[i] << " "; cout << endl;
    now = 0;
    int mx = 0, mn = 0;
    For(i, 1, m) {
        now += (i & 1) ? b[i] : -b[i];
        mx = max(mx, now);
        mn = min(mn, now);
    }
    printf("%d\n", mx - mn);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
