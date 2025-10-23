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
int n, q;
map<int, map<int, int> > ma;

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(q);
    For(i, 1, n) {
        int x, y; read(x); read(y);
        ma[x][y]++;
    }
    while(q--) {
        int x, y, r; read(x); read(y); read(r);
        auto it = ma.lower_bound(x - r);
        int res = 0;
        while(it != ma.end() && it->fir <= x + r) {
            auto it1 = it->second.lower_bound(y - r);
            while(it1 != it->second.end() && it1->first <= y + r) {
                int xi = it->first, yi = it1->first, val = it1->second;
                if(1ll * (xi - x) * (xi - x) + 1ll * (yi - y) * (yi - y) <= 1ll * r * r) res += val;
                it1++;
            }
            it++;
        }
        printf("%d\n", res);
    }
}
