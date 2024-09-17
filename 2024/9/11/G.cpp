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

#define maxn 1000000
int T, n, a[maxn + 5], id[maxn + 5], as[maxn + 5];

void mian() {
    read(n);
    int m = 1 << n;
    For(i, 1, m) read(a[i]);
    For(i, 1, m) as[i] = 0;
    For(i, 1, m) id[i] = i;
    while(m != 1) {
        for(int i = 1; i <= m; i += 2) {
            as[id[i]] = max(as[id[i]], a[id[i + 1]]);
            as[id[i + 1]] = max(as[id[i + 1]], a[id[i]]);
            id[(i + 1) / 2] = a[id[i]] > a[id[i + 1]] ? id[i] : id[i + 1];
        }
        m >>= 1;
    }
    For(i, 1, (1 << n)) cout << as[i] << " "; cout << endl;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
