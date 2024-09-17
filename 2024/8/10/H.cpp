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

#define maxn 400
int n, m, tot[2], tt[2];
pair<int, int> pa[2][maxn + 5], ppa[2][maxn + 5];

multiset<int> se;
vector<int> vec[maxn + 5];

int f[2][maxn + 5][maxn + 5];

int main() {
    freopen("in.txt", "r", stdin);
    read(n); read(m);
    For(i, 1, m) read(pa[0][i].fir), read(pa[0][i].sec), vec[pa[0][i].fir].pb(pa[0][i].sec); tot[0] = m;
    For(i, 1, n - m) read(pa[1][i].fir), read(pa[1][i].sec), vec[pa[1][i].fir].pb(pa[1][i].sec); tot[1] = n - m;
    int mx = 0;
    For(i, 1, maxn) {
        for(auto j : vec[i]) se.insert(j);
        if(se.size()) mx++, se.erase(se.begin());
        while(se.size() && *se.begin() == i) se.erase(se.begin());
    }
    For(o, 0, 1) {
        sort(pa[o] + 1, pa[o] + tot[o] + 1, [](pair<int, int> x, pair<int, int> y) {return x.sec < y.sec;});
        se.clear();
        int now = tot[o];
        Rof(i, maxn, 1) {
            while(now && pa[o][now].sec == i) {
                se.insert(pa[o][now].fir);
                now--;
            }
            if(se.size()) ppa[o][++tt[o]] = { *se.begin(), i }, se.erase(se.begin());
            while(se.size() && *se.begin() == i) se.erase(se.begin());
        }
        reverse(ppa[o] + 1, ppa[o] + tt[o] + 1);
    }
    memset(f, inf, sizeof f);
    f[0][0][0] = 0;
    int o = 0;
    For(i, 0, maxn - 1) {
        For(j, 0, tt[0] - 1) For(p, 0, tt[1] - 1) if(f[o][j][p] != inf) {
            if(ppa[0][j + 1].fir > i + 1 || ppa[0][j + 1].fir < i + 1) f[o ^ 1][j + 1][p] = min(f[o ^ 1][j + 1][p], f[o][j][p]);
            else f[o ^ 1][j + 1][p] = min(f[o ^ 1][j + 1][p], f[o][j][p] + 1);

            if(ppa[1][p + 1].fir > i + 1 || ppa[1][p + 1].fir < i + 1) f[o ^ 1][j][p + 1] = min(f[o ^ 1][j][p + 1], f[o][j][p]);
            else f[o ^ 1][j][p + 1] = min(f[o ^ 1][j][p + 1], f[o][j][p] + 1);
        }
    }
    printf("%d %d\n", mx, f[o][tt[0]][tt[1]]);
}
