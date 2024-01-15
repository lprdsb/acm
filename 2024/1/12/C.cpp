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
int T, n, a[maxn + 5], b[maxn + 5], c[maxn + 5], d[maxn + 5];
vector<pair<int, int> > as;

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        read(n);
        For(i, 1, n) read(a[i]), b[i] = d[i] = c[i] = i;
        sort(b + 1, b + n + 1, [](int _x, int _y) {return a[_x] < a[_y];});
        int fl = 1;
        For(i, 1, n) fl &= a[b[i]] + a[b[n - i + 1]] == a[b[1]] + a[b[n]];
        if(fl) {
            puts("YES");
            For(i, 1, n) if(d[i] != b[i]) {
                int p1 = i, p2 = c[b[i]];
                as.pb({ p1, p2 });
                swap(d[p1], d[p2]);
                c[d[p1]] = p1;
                c[d[p2]] = p2;
            }
            printf("%d\n", as.size());
            for(auto [l, r] : as) printf("%d %d\n", l, r);
        }
        else puts("NO");
        as.resize(0);
    }
}
