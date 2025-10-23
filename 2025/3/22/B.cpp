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

#define maxn 5000
int a[maxn + 5];
vector<pair<int, int> > as;

int main() {
    // freopen("in.txt", "r", stdin);
    int T; read(T);
    while(T--) {
        int n; read(n);
        int mn = 1;
        For(i, 1, n) read(a[i]), mn = min(mn, a[i]);
        if(mn != 0) {
            printf("1\n1 %d\n", n);
            continue;
        }
        as.clear();
        if(a[n] == 0) {
            as.pb({ n - 1, n });
            a[n - 1] = 1;
            n--;
        }
        mn = 1;
        For(i, 1, n) mn = min(mn, a[i]);
        if(mn != 0) {
            as.pb({ 1, n });
            printf("%d\n", as.size());
            for(auto [l, r] : as) printf("%d %d\n", l, r);
            continue;
        }
        as.pb({ 1, n - 1 });
        as.pb({ 1, 2 });
        printf("%d\n", as.size());
        for(auto [l, r] : as) printf("%d %d\n", l, r);
    }
}
