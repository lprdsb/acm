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

#define maxn 300000
int T, n, a[maxn + 5], st[maxn + 5], as[maxn + 5];

void mian() {
    read(n);
    For(i, 1, n) read(a[i]), as[i] = 0;
    int tp = 0;
    st[tp] = 0;
    For(i, 1, n) {
        while(tp && a[i] >= a[st[tp]]) tp--;
        as[i] += i - st[tp] - 1;
        st[++tp] = i;
    }
    st[tp = 0] = n + 1;
    Rof(i, n, 1) {
        while(tp && a[i] >= a[st[tp]]) tp--;
        as[i] += st[tp] - i - 1;
        st[++tp] = i;
    }
    LL res = 0;
    For(i, 1, n) res += as[i];
    cout << res << endl;
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
