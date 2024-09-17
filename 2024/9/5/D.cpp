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
int T, n, a[maxn + 5], num[maxn + 5], vis[maxn + 5];

void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) num[a[i]] = i;
    set<pair<int, int> > se;
    set<pair<int, int> > opt;
    For(i, 1, n) if(num[i]) se.insert({ num[i], i });
    printf("%d\n", se.size());
    int o = 1;
    int now = 1, pos = 1;
    while(se.size()) {
        while(now <= se.begin()->fir) {
            opt.insert({ a[now], now });
            now++;
        }
        while(vis[opt.begin()->fir] || opt.begin()->sec < pos) opt.erase(opt.begin());
        while(vis[(--opt.end())->fir] || (--opt.end())->sec < pos) opt.erase(--opt.end());
        if(o == 1) {
            int tmp = (--opt.end())->fir;
            auto it = opt.lower_bound({ tmp, 0 });
            vector<int> vec;
            while(it->fir == tmp && it->sec < pos) vec.pb(it->sec), it++;
            pos = it->sec;
            for(auto p : vec) opt.erase({ a[p], p });
        }
        else pos = opt.begin()->sec;
        vis[a[pos]] = 1;
        printf("%d ", a[pos]);
        se.erase({ num[a[pos]], a[pos] });
        // pos = res;
        o ^= 1;
    }
    puts("");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) num[i] = vis[i] = 0;
    }
}
