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
int T, n, m, k;
vector<pair<int, int> > vec[maxn + 5];
map<int, int> ma[maxn + 5];
map<int, LL> f[maxn + 5];
int st[maxn + 5];

void mian() {
    read(n); read(m); read(k);
    For(i, 1, n) {
        For(i, 1, m) {
            int x; read(x);
            ma[i][x]++;
        }
    }
    vec[0].pb({ 0, 0 });
    For(i, 1, n) {
        int tp = 0;
        sort(vec[i - 1].begin(), vec[i - 1].end());
        for(auto [x, y] : vec[i - 1]) {
            while(tp > 1
                && 1ll * (vec[i - 1][st[tp]].fir - vec[i - 1][st[tp - 1]].fir) * (y - vec[i - 1][st[tp]].sec)
                - 1ll * (vec[i - 1][st[tp]].sec - vec[i - 1][st[tp - 1]].sec) * (x - vec[i - 1][st[tp]].fir) <= 0) tp--;
            st[++tp] = i;
        }
        int now = 0;
        vector<pair<int, int> > vv;
        for(auto [k, v] : ma[i]) if(k != -1) vv.pb({ v, k });
        sort(vv.begin(), vv.end());
        int now = 1;
        for(auto [v, k] : vv) {
            while(now < tp && 1ll * (vec[i - 1][st[now + 1]].fir - vec[i - 1][st[now]].fir) * v
                - 1ll * (vec[i - 1][st[now + 1]].sec - vec[i - 1][st[now]].sec) >= 0) now++;
            f[i][k] = max(f[i][k], 1ll * ma[i - 1][-1] * ma[i][k])
        }
    }
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
