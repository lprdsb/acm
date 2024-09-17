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
    multiset<int> opt;
    For(i, 1, n) if(num[i]) se.insert({ num[i], i });
    printf("%d\n", se.size());
    int o = 1;
    int now = 1;
    while(se.size()) {
        while(now <= se.begin()->fir) {
            opt.insert(a[now]);
            now++;
        }
        while(vis[*opt.begin()]) opt.erase(opt.begin());
        while(vis[*--opt.end()]) opt.erase(--opt.end());
        int res;
        if(o == 0) res = *--opt.end();
        else res = *opt.begin();
        vis[res] = 1;
        printf("%d\n", res);
        se.erase({ num[res], res });
        o ^= 1;
    }
    puts("");
}

int main() {
    freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) num[i] = vis[i] = 0;
    }
}
