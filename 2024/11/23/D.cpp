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
int T, n, a[maxn + 5];

void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    multiset<int> se[2];
    se[0].insert(inf);
    se[1].insert(inf);
    For(i, 1, n) {
        se[0].insert(-a[i]);
        while(-*se[0].begin() > *se[1].begin()) {
            auto tmp = -*se[0].begin(); se[0].erase(se[0].begin());
            se[1].insert(tmp);
        }
        while(se[1].size() > se[0].size()) {
            se[0].insert(-*se[1].begin());
            se[1].erase(se[1].begin());
        }
        while(se[0].size() > se[1].size() + 1) {
            se[1].insert(-*se[0].begin());
            se[0].erase(se[0].begin());
        }
        if(i & 1) printf("%d ", -*se[0].begin());
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
