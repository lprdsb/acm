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

#define maxn 400000
int n, m;
struct Plank {
    int x, l, r, id, v;
};
bool operator < (cst Plank &x, cst Plank &y) { return x.l < y.l; }
vector<Plank> plank[maxn + 5];
vector<int> id[maxn + 5];

vector<pair<int, int> > ch[maxn + 5];
int S = 0, T, tot = 0;

int main() {
    //freopen("in", "r", stdin);
    read(n); read(m);
    For(i, 1, m) {
        int x, y, l, v; read(x); read(y); read(l); read(v);
        plank[x].pb({ y, y + l - 1, i, v });
    }
    For(i, 1, n) {
        sort(plank[i].begin(), plank[i].end());
        id[i].pb(++tot);
        ch[S].pb({ tot, 0 });
        ch[tot].pb({ S, 0 });
        int pre = tot;
        for(auto p : plank[i]) {
            id[i].pb(++tot);
            ch[pre].pb({ tot, p.v });
            ch[tot].pb({ pre, p.v });
            pre = tot;
        }
    }
    For(i, 2, n) {
        int now = 0;
        For(j, 0, id[i].size() - 1) {
            
        }
    }
}
