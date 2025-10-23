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

int T, n;

#define maxn 100000
pair<int, int> pa[maxn + 5];

void mian() {
    read(n);
    int tp = 0, cnt = 0;
    For(i, 1, n) {
        int l, r; read(l); read(r);
        if(r == 0);
        else pa[++tp] = { l, l + r - 1 };
    }
    n = tp;
    sort(pa + 1, pa + n + 1);
    set<pair<int, int> > se;
    int mx = 1;
    For(i, 1, n) {
        while(se.size() && se.begin()->fir < pa[i].fir) {
            mx = max(mx, se.begin()->sec + 1);
            se.erase(se.begin());
        }
        se.insert({ pa[i].sec, mx });
    }
    printf("%d\n", mx + cnt);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
