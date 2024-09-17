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
int T, n;
LL a[maxn + 5], b[maxn + 5];

int res = 0;
pair<LL, LL> st[maxn + 5];
void mian() {
    read(n);
    For(i, 1, n) read(a[i]), read(b[i]);
    int tp = 0;
    For(i, 1, n) {
        while(tp) {
            if(st[tp].fir == b[i]) a[i] += st[tp].sec - st[tp + 1].sec, tp--;
            else if(st[tp].sec <= a[i]) tp--;
            else break;
        }
        st[++tp] = { b[i], a[i] };
        printf("%lld ", st[1].sec);
    }
    puts("");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
