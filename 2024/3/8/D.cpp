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
int T, n, m, a[maxn + 5], b[maxn + 5];

bool chk(int x) {
    int pa = 2, ok = 0;
    For(i, x + 1, n) {
        if(a[pa] >= b[i] || pa == n + 1) {
            if(!ok) {
                if(a[1] < b[i]) ok = 1;
                else return 0;
            }
            else return 0;
        }
        else pa++;
    }
    return 1;
}

void mian() {
    read(n); read(m);
    For(i, 2, n) read(a[i]); a[1] = 1;
    sort(a + 1, a + n + 1);
    For(i, 1, n) read(b[i]);
    sort(b + 1, b + n + 1);
    a[1] = 1;
    int l = 0, r = n;
    while(l < r) {
        int md = l + r >> 1;
        if(chk(md)) r = md;
        else l = md + 1;
    }
    int res = l;
    l = 1; r = m + 1;
    while(l < r) {
        int md = l + r >> 1;
        a[1] = md;
        if(!chk(res)) r = md;
        else l = md + 1;
    }
    printf("%lld\n", 1ll * res * m + m - l + 1);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }

}
