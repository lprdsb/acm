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
struct Tree {
    LL tr[maxn + 5][2];
    void ins(int x, int y) {
        int _x = x;
        while(x <= maxn) {
            tr[x][0] += y;
            tr[x][1] += _x * y;
            x += x & -x;
        }
    }
    void ins(int l, int r, int x) {
        ins(l, x);
        ins(r + 1, -x);
    }
    LL que(int x) {
        int _x = x;
        LL res = 0;
        while(x) {
            res += (_x + 1) * tr[x][0] - tr[x][1];
            x -= x & -x;
        }
        return res;
    }
    LL que(int l, int r) { return que(r) - que(l - 1); }
} tr[2];

set<int> se[2];

int n, m, q;
int main() {
    //freopen("in", "r", stdin);
    read(n); read(m); read(q);
    
}
