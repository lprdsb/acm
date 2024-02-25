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
int T, n, a[maxn + 5];

map<int, vector<int> > ma;
int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        read(n);
        int mx = 0;
        For(i, 1, n) {
            read(a[i]);
            ma[a[i] + i].pb(1 + a[i]);
            mx = max(mx, a[i] + i);
        }
        multiset<int> se;
        Rof(i, mx, 1) {
            for(auto j : ma[i]) se.insert(-j);
            if(se.size()) {
                printf("%d ", i);
                se.erase(se.begin());
            }
            while(se.size() && -*se.begin() == i) se.erase(se.begin());
            if(!se.size()) {
                auto it = ma.lower_bound(i);
                if(it != ma.begin()) {
                    it--;
                    i = it->fir + 1;
                }
                else break;
            }
        }
        puts("");
        ma.clear();
    }
}
